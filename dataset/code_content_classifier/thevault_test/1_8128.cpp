void OnPointCloudAvailableRouter(void* context,
                                 const TangoPointCloud* point_cloud) {
  SynchronizationApplication* app =
      static_cast<SynchronizationApplication*>(context);
  app->OnPointCloudAvailable(point_cloud);
}