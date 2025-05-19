# Utility AI
Unreal Engine Plugin [...]

> [!NOTE]
> Some videos might not load properly when not viewed on the GitHub page.

## Artificial Psychology

---

We start by defining the difference between agents and players.
- Agents don't really have psychology
- But players do have psychology

So how can we leverage our players' innate psychology to create the illusion of it in our agents?

## Player Psychology

### Prisoner's Dilemma
The Prisoner's Dilemma is a standard example of a game theory problem.  
It demonstrates why two completely rational individuals might not cooperate, even if it appears that it is in their best interest to do so.

<img src="https://i.insider.com/5756c8da9105841d008c7255?width=800&format=jpeg&auto=webp" alt="Prisoner's Dilemma" width="400">
<!--
### Kuleshov Effect
The Kuleshov Effect is a film editing effect that demonstrates how the same image can evoke different emotions depending on the context in which it is presented.  
In the absence of any defining information, people project what they believe should be there.


<video width="320" height="240" src="https://github.com/user-attachments/assets/3b3356f2-ae17-42e7-9937-19b5b1fb30d6">
<source src="https://github.com/user-attachments/assets/3b3356f2-ae17-42e7-9937-19b5b1fb30d6" type="video/mp4">
</video>
-->

---

## Actions
Each action comes with a set of axis that might look like this:
- Axis: ``Input (x)`` Parameters: ``curve-type, m, k, b, c``
  
E.g.

<table style="outline:none; width: auto">
    <td style="padding-left:40px; padding-right:40px; outline:none" valign="top">
      <b style="font-size: 20px">Move to Cover</b><br>
      <table>
        <tr><td>Current Threat Level</td></tr>
        <tr><td>My Health</td></tr>
        <tr><td>My Ammo</td></tr>
        <tr><td>Distance from me *</td></tr>
        <tr><td>Quality of cover *</td></tr>
      </table>
    </td>
  <td style="padding-left:40px; padding-right:40px; outline:none" valign="top">
    <b style="font-size: 20px">Attack someone</b><br>
    <table>
      <tr><td>Distance from me *</td></tr>
      <tr><td>Their Health *</td></tr>
      <tr><td>Their Ammo *</td></tr>
    </table>
  </td>
</table>

[*]() Per targeted object



### Actions per Target
Actions with targets are scored per target.  
For example, when considering the action ``Attack Someone``, we need to score each potential target first.  
Each scored action is then pushed onto a list of possible actions that the agent can perform.
(Scored Action List)

---

## Scoring (Response Curves)
The scoring of an action is done by using a response curve.  
A response curve is a mathematical representation of a relationship
such as mapping a concrete value to an associated abstract value.
- Distance ➡️ Threat
- Ammo ➡️Reload Necessity
- Health ➡️ Heal Necessity

Defining a response curve
- Curve Type
  - Linear _(straight)_ ``y = m * x + b``
  - Quadratic _(parabolic)_ ``y = m * (x - c)^k + b``
  - Logistic _(s-shaped)_ ``y = k * (1 / (1 + m * e^(-x + c) ) + b``
  - Logit _(s-shaped)_ `
- 4 parameter values
  - m _slope_
  - k _exponent_
  - b _y-intercept_
  - c _x-intercept_

Thus, a curve being described in ``(Type, m, k, b, c)`` format.  
E.g.:
- ``(Linear, 0.5, 1.0, 0.25, 0.0)``  
<img alt="linear curve" src="Resources/img/Utility%20Theory_%20Linear%20Curve.png" width="400"/>


- ``(Logistic, 50.0, -0.95, 1.0, 0.6)``  
<img alt="linear curve" src="Resources/img/Utility%20Theory_%20Logistic%20Curve.png" width="400"/>

A response curve gets evaluated with the following process:
- ``(x, Type, m, k, b, c)``
- Clamping input (0..1)
- Calculate using the appropriate formula type
- Clamp output (0..1)
- Return ``y``

After each axis is evaluated, the results will be multiplied together to get the final score for the action.  
- ``action-score`` = ``axis1 * axis2 * axis3 * ...``  
  <img alt="image" src="Resources/img/Utility%20Theory_Action%20Hierarchy.png" width="600"/>


Note, as the output scores of each axis are normalized to 0..1, the final score will also be normalized to 0..1.

---

## Inputs
Input can be gathered from various sources.  
E.g.:
<table style="outline:none; width: auto">
    <td style="padding-left:40px; padding-right:40px; outline:none" valign="top">
      <b style="font-size: 20px">Agent (Self)</b><br>
      <table>
        <tr><td>My Health</td></tr>
        <tr><td>My Ammo</td></tr>
        <tr><td>My Weapon</td></tr>
        <tr><td>My Intelligence</td></tr>
      </table>
    </td>
  <td style="padding-left:40px; padding-right:40px; outline:none" valign="top">
    <b style="font-size: 20px">Other Agents</b><br>
    <table>
      <tr><td>Distance from me *</td></tr>
      <tr><td>Their Health *</td></tr>
      <tr><td>Their Ammo *</td></tr>
      <tr><td>Their Strength *</td></tr>
    </table>
  </td>
<td style="padding-left:40px; padding-right:40px; outline:none" valign="top">
      <b style="font-size: 20px">World Info</b><br>
      <table>
        <tr><td>Distance between A & B</td></tr>
        <tr><td>Num of Allies/Enemies</td></tr>
        <tr><td>Elapsed Time</td></tr>
      </table>
    </td>
<td style="padding-left:40px; padding-right:40px; outline:none" valign="top">
      <b style="font-size: 20px">Aggregated Info</b><br>
      <table>
        <tr><td>Blackboard</td></tr>
        <tr><td>Influence Map</td></tr>
        <tr><td>Perception</td></tr>
      </table>
    </td>
</table>

As the X-Range of the response curves are clamped from 0..1, the input values also need to be normalized to this range.  
In some cases the data is normalized by default (``Health %``, ``Ammo %``).  
But in other cases, the data is more cumbersome to normalize.  
What would we do then?

### Normalizing Non-Standard Inputs
For normalizing those types of inputs, we define "bookends"
- ``A``/``0`` is the least we care about
- ``B``/``1`` is the most we care about  

Anything outside [A; B] gets clamped to 0 or 1 respectively.

#### Static Bookends
- In the example of distance we would pick a max distance beyond which everything else will get treated as the same.  
Meaning that a max distance of 50 meters and everything else >50 meters will be treated as 1.0.


- Or the number of enemies could be clamped by a "bookend" value of 8,
as anything above that number just counts as "many enemies."

#### Variable Bookends
- The range of the current weapon that can vary per weapon class.  
"Who could I shoot with this weapon?"


- Speed of the agent.  
"How far can I travel within 3 seconds?"


- Effective Range (WeaponRange + Speed)  
"Who could I shoot within 3 seconds?"

---

## The Flow
<img alt="image" src="Resources/img/Utility%20Theory_Flow.png" width="600"/>  

Each calculated utility is added to a vector of possible actions.
- Action
- Object ``optional target e.g. shooting someone``
- Score ``the final score this action scored``

From that Potential Action List we will select one action using:
- Highest Score
- Weighted random selection
- Etc.

## Metrics
- Desire ??
- Utility
- Mental Model
  - Rationality
  - Aggressiveness
  - Intelligence


## Bucketing

## Resources
- https://medium.com/@morganwalkupdev/ai-made-easy-with-utility-ai-fef94cd36161
- https://medium.com/@morganwalkupdev/easy-ai-in-unreal-engine-c0f4ba1998cc
- https://www.gameaipro.com/GameAIPro/GameAIPro_Chapter09_An_Introduction_to_Utility_Theory.pdf
- https://www.tomlooman.com/unreal-engine-utility-ai-part1/
- https://www.gdcvault.com/play/1021848/Building-a-Better-Centaur-AI
- https://www.gdcvault.com/play/1012410/Improving-AI-Decision-Modeling-Through
- https://www.intrinsicalgorithm.com/techs.php
- http://totalai.org/doc-goap.html
- https://www.youtube.com/watch?v=jyJpO0HdqCg
- https://www.youtube.com/watch?v=xaEmJRf5K7k