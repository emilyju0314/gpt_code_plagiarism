void OnPointCloudAvailableRouter(void* context,
                                 const TangoPointCloud* point_cloud) {
  PlaneFittingApplication* app = static_cast<PlaneFittingApplication*>(context);
  app->OnPointCloudAvailable(point_cloud);
}