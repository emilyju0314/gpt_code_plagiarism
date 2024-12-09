ScrollView::Color POLY_BLOCK::ColorForPolyBlockType(PolyBlockType type) {
  // Keep kPBColors in sync with PolyBlockType.
  const ScrollView::Color kPBColors[PT_COUNT] = {
      ScrollView::WHITE,       // Type is not yet known. Keep as the 1st element.
      ScrollView::BLUE,        // Text that lives inside a column.
      ScrollView::CYAN,        // Text that spans more than one column.
      ScrollView::MEDIUM_BLUE, // Text that is in a cross-column pull-out
                               // region.
      ScrollView::AQUAMARINE,  // Partition belonging to an equation region.
      ScrollView::SKY_BLUE,    // Partition belonging to an inline equation
                               // region.
      ScrollView::MAGENTA,     // Partition belonging to a table region.
      ScrollView::GREEN,       // Text-line runs vertically.
      ScrollView::LIGHT_BLUE,  // Text that belongs to an image.
      ScrollView::RED,         // Image that lives inside a column.
      ScrollView::YELLOW,      // Image that spans more than one column.
      ScrollView::ORANGE,      // Image in a cross-column pull-out region.
      ScrollView::BROWN,       // Horizontal Line.
      ScrollView::DARK_GREEN,  // Vertical Line.
      ScrollView::GREY         // Lies outside of any column.
  };
  if (type < PT_COUNT) {
    return kPBColors[type];
  }
  return ScrollView::WHITE;
}