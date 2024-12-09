void vtkOpenGLState::Initialize(vtkOpenGLRenderWindow *)
{
  this->TextureUnitManager->Initialize();

  this->CurrentState.Blend
    ? ::glEnable(GL_BLEND) : ::glDisable(GL_BLEND);
  this->CurrentState.DepthTest
    ? ::glEnable(GL_DEPTH_TEST) : ::glDisable(GL_DEPTH_TEST);
  this->CurrentState.StencilTest
    ? ::glEnable(GL_STENCIL_TEST) : ::glDisable(GL_STENCIL_TEST);
  this->CurrentState.ScissorTest
    ? ::glEnable(GL_SCISSOR_TEST) : ::glDisable(GL_SCISSOR_TEST);
  this->CurrentState.CullFace
    ? ::glEnable(GL_CULL_FACE) : ::glDisable(GL_CULL_FACE);

#ifdef GL_MULTISAMPLE
  this->CurrentState.MultiSample = glIsEnabled(GL_MULTISAMPLE) == GL_TRUE;
#endif

  // initialize blending for transparency
  ::glBlendFuncSeparate(
    this->CurrentState.BlendFunc[0],
    this->CurrentState.BlendFunc[1],
    this->CurrentState.BlendFunc[2],
    this->CurrentState.BlendFunc[3]);

  ::glClearColor(
    this->CurrentState.ClearColor[0],
    this->CurrentState.ClearColor[1],
    this->CurrentState.ClearColor[2],
    this->CurrentState.ClearColor[3]);

  ::glColorMask(
    this->CurrentState.ColorMask[0],
    this->CurrentState.ColorMask[1],
    this->CurrentState.ColorMask[2],
    this->CurrentState.ColorMask[3]);

  ::glDepthFunc( this->CurrentState.DepthFunc );

#ifdef GL_ES_VERSION_3_0
  ::glClearDepthf(this->CurrentState.ClearDepth);
#else
  ::glClearDepth(this->CurrentState.ClearDepth);
#endif

  ::glDepthMask(this->CurrentState.DepthMask);

  ::glViewport(
    this->CurrentState.Viewport[0],
    this->CurrentState.Viewport[1],
    this->CurrentState.Viewport[2],
    this->CurrentState.Viewport[3]);

  ::glScissor(
    this->CurrentState.Scissor[0],
    this->CurrentState.Scissor[1],
    this->CurrentState.Scissor[2],
    this->CurrentState.Scissor[3]);

  ::glCullFace(this->CurrentState.CullFaceMode);

  ::glBlendEquationSeparate(
    this->CurrentState.BlendEquationValue1,
    this->CurrentState.BlendEquationValue2);

  // strictly query values below here
  ::glGetIntegerv(GL_MAX_TEXTURE_SIZE,
    &this->CurrentState.MaxTextureSize);
  ::glGetIntegerv(GL_MAJOR_VERSION,
    &this->CurrentState.MajorVersion);
  ::glGetIntegerv(GL_MINOR_VERSION,
    &this->CurrentState.MinorVersion);
}