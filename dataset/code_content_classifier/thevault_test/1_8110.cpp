void OnTextureAvailableRouter(void* context, TangoCameraId id) {
  tango_video_stabilization::VideoStabilizationApp* app =
      static_cast<tango_video_stabilization::VideoStabilizationApp*>(context);
  app->OnTextureAvailable(id);
}