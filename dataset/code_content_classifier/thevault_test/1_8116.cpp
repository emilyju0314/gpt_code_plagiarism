void OnFrameAvailableRouter(void* context, TangoCameraId,
                            const TangoImageBuffer* buffer) {
  tango_marker_detection::MarkerDetectionApp* app =
      static_cast<tango_marker_detection::MarkerDetectionApp*>(context);
  app->OnFrameAvailable(buffer);
}