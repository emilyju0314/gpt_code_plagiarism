void egl_window_initialize(EGLWindowCtx* egl_ctx) {
    egl_ctx->mDisplay = EGL_NO_DISPLAY;
    egl_ctx->mSurface = EGL_NO_SURFACE;
    egl_ctx->mContext = EGL_NO_CONTEXT;

    // create os-window and OpenGLES-2.0 environment
    opengles_20_init(egl_ctx);
}