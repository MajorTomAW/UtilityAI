// Author: Tom Werner (MajorT), 2025


#include "UtilityComponent.h"

#include "UtilityAILogging.h"
#include "Perception/AIPerceptionComponent.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(UtilityComponent)

UUtilityComponent::UUtilityComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bTickedOnce = false;

	bWantsInitializeComponent = true;
}

void UUtilityComponent::StartLogic()
{
	Super::StartLogic();
}

void UUtilityComponent::StopLogic(const FString& Reason)
{
	Super::StopLogic(Reason);
}

void UUtilityComponent::RestartLogic()
{
	Super::RestartLogic();
}

void UUtilityComponent::InitializeComponent()
{
	Super::InitializeComponent();

	// Cache perception component if the owner has one
	if (const AActor* Owner = GetOwner())
	{
		PerceptionComp = Owner->FindComponentByClass<UAIPerceptionComponent>();
	}
}

void UUtilityComponent::UninitializeComponent()
{
	Super::UninitializeComponent();
}

void UUtilityComponent::RegisterComponentTickFunctions(bool bRegister)
{
	if (bRegister)
	{
		ScheduleNextTick(0.f);
	}
	
	Super::RegisterComponentTickFunctions(bRegister);
}

void UUtilityComponent::SetComponentTickEnabled(bool bEnabled)
{
	const bool bWasEnabled = IsComponentTickEnabled();
	Super::SetComponentTickEnabled(bEnabled);

	// If enabling the component, this acts like a new component to tick. So act like we were never ticked
	if (!bWasEnabled && IsComponentTickEnabled())
	{
		bTickedOnce = false;
		ScheduleNextTick(0.f);
	}
}

void UUtilityComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	const UWorld* World = GetWorld();
	const bool bUseWorldDTForCurrentFrame = (ThisTickFunction != nullptr && IsValid(World));

	CurrentFrameDeltaTime = bUseWorldDTForCurrentFrame ? World->GetDeltaSeconds() : DeltaTime;

	// Make sure we ticked after being requested to tick on the next frame
	if (bTickedOnce && NextTickDeltaTime == 0.f && bUseWorldDTForCurrentFrame)
	{
		const double CurrentGameTime = World->GetTimeSeconds();
		if ((CurrentGameTime - LastRequestedDeltaTimeGameTime - CurrentFrameDeltaTime) > KINDA_SMALL_NUMBER)
		{
			UE_VLOG(GetOwner(), LogUtilityAI, Error, TEXT("UtilityComp(%llu) expected to be tick next frame, current dt(%f), calculated dt(%f)"),
				GFrameCounter, CurrentFrameDeltaTime, CurrentGameTime - LastRequestedDeltaTimeGameTime);
		}
	}

	// Check if we've reached the asked DeltaTime, if not, then reschedule and accumulate
	NextTickDeltaTime -= DeltaTime;
	if (NextTickDeltaTime > 0.f)
	{
		if (ThisTickFunction != nullptr && NextTickDeltaTime > KINDA_SMALL_NUMBER)
		{
			UE_VLOG(GetOwner(), LogUtilityAI, Error, TEXT("UtilityComp(%llu) did not need to be ticked, ask dt of %fs got %fs with a diff of %fs."),
				GFrameCounter, NextTickDeltaTime + AccumulatedTickDeltaTime + DeltaTime, DeltaTime + AccumulatedTickDeltaTime, NextTickDeltaTime);
		}

		AccumulatedTickDeltaTime += DeltaTime;
		ScheduleNextTick(NextTickDeltaTime);
		return;
	}

	AccumulatedTickDeltaTime += DeltaTime;
	ON_SCOPE_EXIT
	{
		AccumulatedTickDeltaTime = 0.f;
	};

	DeltaTime = AccumulatedTickDeltaTime;
	
	const bool bWasTickedOnce = bTickedOnce;
	bTickedOnce = true;

	bool bDoneSomething = !MessagesToProcess.IsEmpty();
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	check(IsValid(this));
}

void UUtilityComponent::ScheduleNextTick(float NextDesiredDeltaTime)
{
	NextTickDeltaTime = NextDesiredDeltaTime;

	UE_VLOG(GetOwner(), LogUtilityAI, VeryVerbose, TEXT("UtilityComp(%llu) scheduled next tick in %fs, asked %fs"),
		GFrameCounter, NextTickDeltaTime, NextDesiredDeltaTime);
	

	if (IsComponentTickEnabled())
	{
		SetComponentTickEnabled(false);
	}
	else
	{
		SetComponentTickEnabled(true);

		// We need to force a small dt to tell teh TickTaskManager we might not want to be tick every frame.
		SetComponentTickIntervalAndCooldown(!bTickedOnce && NextTickDeltaTime < KINDA_SMALL_NUMBER ? KINDA_SMALL_NUMBER : NextTickDeltaTime);
	}

	const UWorld* World = GetWorld();
	LastRequestedDeltaTimeGameTime = IsValid(World) ? World->GetTimeSeconds() : 0.f;
}

void UUtilityComponent::CachePerceptionComponent(UAIPerceptionComponent* InPerceptionComp)
{
	if (IsValid(InPerceptionComp))
	{
		PerceptionComp = InPerceptionComp;
	}
}
