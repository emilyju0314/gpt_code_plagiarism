MFOUTLINE ConvertOutline(TESSLINE *outline) {
  auto MFOutline = NIL_LIST;

  if (outline == nullptr || outline->loop == nullptr) {
    return MFOutline;
  }

  auto StartPoint = outline->loop;
  auto EdgePoint = StartPoint;
  do {
    auto NextPoint = EdgePoint->next;

    /* filter out duplicate points */
    if (EdgePoint->pos.x != NextPoint->pos.x || EdgePoint->pos.y != NextPoint->pos.y) {
      auto NewPoint = new MFEDGEPT;
      NewPoint->ClearMark();
      NewPoint->Hidden = EdgePoint->IsHidden();
      NewPoint->Point.x = EdgePoint->pos.x;
      NewPoint->Point.y = EdgePoint->pos.y;
      MFOutline = push(MFOutline, NewPoint);
    }
    EdgePoint = NextPoint;
  } while (EdgePoint != StartPoint);

  if (MFOutline != nullptr) {
    MakeOutlineCircular(MFOutline);
  }
  return MFOutline;
}