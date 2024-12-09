static void SetupConfigMap(ShapeTable *shape_table, IndexMapBiDi *config_map) {
  int num_configs = shape_table->NumShapes();
  config_map->Init(num_configs, true);
  config_map->Setup();
  for (int c1 = 0; c1 < num_configs; ++c1) {
    // Only process ids that are not already merged.
    if (config_map->SparseToCompact(c1) == c1) {
      Shape *shape1 = shape_table->MutableShape(c1);
      // Find all the subsequent shapes that are equal.
      for (int c2 = c1 + 1; c2 < num_configs; ++c2) {
        if (shape_table->MutableShape(c2)->IsEqualUnichars(shape1)) {
          config_map->Merge(c1, c2);
        }
      }
    }
  }
  config_map->CompleteMerges();
}