void onFrameAvailableRouter(void* context, TangoCameraId id,
                            const TangoImageBuffer* buffer) {
  mesh_builder::MeshBuilderApp* app =
      static_cast<mesh_builder::MeshBuilderApp*>(context);
  app->onFrameAvailable(id, buffer);
}