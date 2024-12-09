void onPointCloudAvailableRouter(void* context,
                                 const TangoPointCloud* point_cloud) {
  mesh_builder::MeshBuilderApp* app =
      static_cast<mesh_builder::MeshBuilderApp*>(context);
  app->onPointCloudAvailable(point_cloud);
}