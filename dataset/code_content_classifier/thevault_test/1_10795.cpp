void TextlineProjection::TransformToPixCoords(const DENORM *denorm, TPOINT *pt) const {
  if (denorm != nullptr) {
    // Denormalize the point.
    denorm->DenormTransform(nullptr, *pt, pt);
  }
  pt->x = ImageXToProjectionX(pt->x);
  pt->y = ImageYToProjectionY(pt->y);
}