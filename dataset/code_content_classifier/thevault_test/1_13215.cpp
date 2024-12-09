gfx::Transform GetTargetTransformForBoundsAnimation(const gfx::Rect& from,
                                                    const gfx::Rect& to) {
  gfx::Transform transform;
  transform.Translate(to.x() - from.x(), to.y() - from.y());
  transform.Scale(to.width() / static_cast<float>(from.width()),
                  to.height() / static_cast<float>(from.height()));
  return transform;
}