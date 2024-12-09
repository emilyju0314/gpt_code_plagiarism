void CharNormalizeOutline(MFOUTLINE Outline, const DENORM &cn_denorm) {
  MFOUTLINE First, Current;
  MFEDGEPT *CurrentPoint;

  if (Outline == NIL_LIST) {
    return;
  }

  First = Outline;
  Current = First;
  do {
    CurrentPoint = PointAt(Current);
    FCOORD pos(CurrentPoint->Point.x, CurrentPoint->Point.y);
    cn_denorm.LocalNormTransform(pos, &pos);
    CurrentPoint->Point.x = (pos.x() - UINT8_MAX / 2) * MF_SCALE_FACTOR;
    CurrentPoint->Point.y = (pos.y() - UINT8_MAX / 2) * MF_SCALE_FACTOR;

    Current = NextPointAfter(Current);
  } while (Current != First);

}