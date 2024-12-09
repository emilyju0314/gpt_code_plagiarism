void WriteShapeTable(const std::string &file_prefix, const ShapeTable &shape_table) {
  std::string shape_table_file = file_prefix;
  shape_table_file += kShapeTableFileSuffix;
  FILE *fp = fopen(shape_table_file.c_str(), "wb");
  if (fp != nullptr) {
    if (!shape_table.Serialize(fp)) {
      fprintf(stderr, "Error writing shape table: %s\n", shape_table_file.c_str());
    }
    fclose(fp);
  } else {
    fprintf(stderr, "Error creating shape table: %s\n", shape_table_file.c_str());
  }
}