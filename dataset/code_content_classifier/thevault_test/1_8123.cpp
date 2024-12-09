void onPointCloudAvailableRouter(void* context,
                                 const TangoPointCloud* point_cloud) {
  tango_point_cloud::PointCloudApp* app =
      static_cast<tango_point_cloud::PointCloudApp*>(context);
  app->onPointCloudAvailable(point_cloud);
}