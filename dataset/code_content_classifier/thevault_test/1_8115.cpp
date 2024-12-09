void onTextureAvailableRouter(void* context, TangoCameraId id) {
  tango_marker_detection::MarkerDetectionApp* app =
      static_cast<tango_marker_detection::MarkerDetectionApp*>(context);
  app->onTextureAvailable(id);
}