void ComputeDirection(MFEDGEPT *Start, MFEDGEPT *Finish, float MinSlope, float MaxSlope) {
  FVECTOR Delta;

  Delta.x = Finish->Point.x - Start->Point.x;
  Delta.y = Finish->Point.y - Start->Point.y;
  if (Delta.x == 0) {
    if (Delta.y < 0) {
      Start->Slope = -FLT_MAX;
      Start->Direction = south;
    } else {
      Start->Slope = FLT_MAX;
      Start->Direction = north;
    }
  } else {
    Start->Slope = Delta.y / Delta.x;
    if (Delta.x > 0) {
      if (Delta.y > 0) {
        if (Start->Slope > MinSlope) {
          if (Start->Slope < MaxSlope) {
            Start->Direction = northeast;
          } else {
            Start->Direction = north;
          }
        } else {
          Start->Direction = east;
        }
      } else if (Start->Slope < -MinSlope) {
        if (Start->Slope > -MaxSlope) {
          Start->Direction = southeast;
        } else {
          Start->Direction = south;
        }
      } else {
        Start->Direction = east;
      }
    } else if (Delta.y > 0) {
      if (Start->Slope < -MinSlope) {
        if (Start->Slope > -MaxSlope) {
          Start->Direction = northwest;
        } else {
          Start->Direction = north;
        }
      } else {
        Start->Direction = west;
      }
    } else if (Start->Slope > MinSlope) {
      if (Start->Slope < MaxSlope) {
        Start->Direction = southwest;
      } else {
        Start->Direction = south;
      }
    } else {
      Start->Direction = west;
    }
  }
  Finish->PreviousDirection = Start->Direction;
}