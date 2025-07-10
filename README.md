```mermaid
flowchart TD
  Input[Teacher Inputs: grade, subject, objectives, student profiles]

  subgraph Agents
    C[Curriculum Agent]
    O[Content Agent]
    A[Assessment Agent]
    P[Personalization Agent]
  end

  Input --> C
  Input --> O
  Input --> A
  Input --> P

  C --> D1[Draft Plan]
  O --> D1
  A --> D1
  P --> D1

  D1 --> O2[Content Agent (refine)]
  D1 --> C2[Curriculum Agent (refine)]
  O2 --> Review[Teacher Review]
  C2 --> Review
  D1 --> Review

  Review --> D2[Refined Draft]
  D2 --> Final[Final Weekly Plan]
  Final --> Export[Export to LMS / Calendar / PDF]
```
