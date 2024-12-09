SVMenuNode *SVPaint::BuildMenuBar() {
  auto *root = new SVMenuNode(); // Empty root node

  // Create some submenus and add them to the root.
  SVMenuNode *click = root->AddChild("Clicking");
  SVMenuNode *drag = root->AddChild("Dragging");

  // Put some nodes into the submenus.
  click->AddChild("Point to Point Drawing", // Caption.
                  1);                       // command_id.
  click->AddChild("Point Drawing", 2);
  click->AddChild("Text Drawing", 3);
  drag->AddChild("Line Drawing", 4);
  drag->AddChild("Rectangle Drawing", 5);
  drag->AddChild("Ellipse Drawing", 6);
  return root;
}