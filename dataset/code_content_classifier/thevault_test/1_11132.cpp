void C_OUTLINE::FakeOutline(const TBOX &box, C_OUTLINE_LIST *outlines) {
  C_OUTLINE_IT ol_it(outlines);
  // Make a C_OUTLINE from the bounds. This is a bit of a hack,
  // as there is no outline, just a bounding box, but it works nicely.
  CRACKEDGE start;
  start.pos = box.topleft();
  auto *outline = new C_OUTLINE(&start, box.topleft(), box.botright(), 0);
  ol_it.add_to_end(outline);
}