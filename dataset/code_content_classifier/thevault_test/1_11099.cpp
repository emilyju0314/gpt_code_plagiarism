ShapeTable *LoadShapeTable(const std::string &file_prefix) {
  ShapeTable *shape_table = nullptr;
  std::string shape_table_file = file_prefix;
  shape_table_file += kShapeTableFileSuffix;
  TFile shape_fp;
  if (shape_fp.Open(shape_table_file.c_str(), nullptr)) {
    shape_table = new ShapeTable;
    if (!shape_table->DeSerialize(&shape_fp)) {
      delete shape_table;
      shape_table = nullptr;
      tprintf("Error: Failed to read shape table %s\n", shape_table_file.c_str());
    } else {
      int num_shapes = shape_table->NumShapes();
      tprintf("Read shape table %s of %d shapes\n", shape_table_file.c_str(), num_shapes);
    }
  } else {
    tprintf("Warning: No shape table file present: %s\n", shape_table_file.c_str());
  }
  return shape_table;
}