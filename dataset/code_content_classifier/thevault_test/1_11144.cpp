void C_OUTLINE::plot_normed(const DENORM &denorm, ScrollView::Color colour,
                            ScrollView *window) const {
  window->Pen(colour);
  if (stepcount == 0) {
    window->Rectangle(box.left(), box.top(), box.right(), box.bottom());
    return;
  }
  const DENORM *root_denorm = denorm.RootDenorm();
  ICOORD pos = start; // current position
  FCOORD f_pos = sub_pixel_pos_at_index(pos, 0);
  FCOORD pos_normed;
  denorm.NormTransform(root_denorm, f_pos, &pos_normed);
  window->SetCursor(IntCastRounded(pos_normed.x()), IntCastRounded(pos_normed.y()));
  for (int s = 0; s < stepcount; pos += step(s++)) {
    int edge_weight = edge_strength_at_index(s);
    if (edge_weight == 0) {
      // This point has conflicting gradient and step direction, so ignore it.
      continue;
    }
    FCOORD f_pos = sub_pixel_pos_at_index(pos, s);
    FCOORD pos_normed;
    denorm.NormTransform(root_denorm, f_pos, &pos_normed);
    window->DrawTo(IntCastRounded(pos_normed.x()), IntCastRounded(pos_normed.y()));
  }
}