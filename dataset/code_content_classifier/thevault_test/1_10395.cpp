void ChangeDirection(MFOUTLINE Start, MFOUTLINE End, DIRECTION Direction) {
  MFOUTLINE Current;

  for (Current = Start; Current != End; Current = NextPointAfter(Current)) {
    PointAt(Current)->Direction = Direction;
  }

  PointAt(End)->PreviousDirection = Direction;

}