SVMenuNode *SVPaint::BuildPopupMenu() {
  auto *root = new SVMenuNode(); // Empty root node
  // Initial color is white, so we  all values to 255.
  root->AddChild("R",                 // Shown caption.
                 1,                   // assoc. command_id.
                 "255",               // initial value.
                 "Red Color Value?"); // Shown description.
  root->AddChild("G", 2, "255", "Green Color Value?");
  root->AddChild("B", 3, "255", "Blue Color Value?");
  return root;
}