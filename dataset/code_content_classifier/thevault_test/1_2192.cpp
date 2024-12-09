void PaperRenderer::DrawRect(float width, float height, const PaperMaterialPtr& material,
                             PaperDrawableFlags flags) {
  const vec2 extent(width, height);
  DrawRect(-0.5f * extent, 0.5f * extent, material, flags);
}