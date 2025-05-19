// Author: Tom Werner (MajorT), 2025

#pragma once

UTILITYAI_API DECLARE_LOG_CATEGORY_EXTERN(LogUtilityAI, Log, All);

#define UTILITYAI_LOG(Format, ...) UE_LOG(LogUtilityAI, Log, TEXT(Format), ##__VA_ARGS__)
#define UTILITYAI_WARN(Format, ...) UE_LOG(LogUtilityAI, Warning, TEXT(Format), ##__VA_ARGS__)
#define UTILITYAI_ERROR(Format, ...) UE_LOG(LogUtilityAI, Error, TEXT(Format), ##__VA_ARGS__)