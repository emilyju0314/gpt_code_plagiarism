vtkOpenGLState::vtkOpenGLState()
{
  this->TextureUnitManager = vtkTextureUnitManager::New();

  this->CurrentState.Blend = true;
  this->CurrentState.DepthTest = true;
  this->CurrentState.StencilTest = false;
  this->CurrentState.ScissorTest = true;
  this->CurrentState.CullFace = false;

  this->CurrentState.MultiSample = false;

  // initialize blending for transparency
  this->CurrentState.BlendFunc[0] = GL_SRC_ALPHA;
  this->CurrentState.BlendFunc[1] = GL_ONE_MINUS_SRC_ALPHA;
  this->CurrentState.BlendFunc[2] = GL_ONE;
  this->CurrentState.BlendFunc[3] = GL_ONE_MINUS_SRC_ALPHA;

  this->CurrentState.ClearColor[0] = 0.0;
  this->CurrentState.ClearColor[1] = 0.0;
  this->CurrentState.ClearColor[2] = 0.0;
  this->CurrentState.ClearColor[3] = 0.0;

  this->CurrentState.ColorMask[0] = GL_TRUE;
  this->CurrentState.ColorMask[1] = GL_TRUE;
  this->CurrentState.ColorMask[2] = GL_TRUE;
  this->CurrentState.ColorMask[3] = GL_TRUE;

  this->CurrentState.DepthFunc = GL_LEQUAL;

  this->CurrentState.ClearDepth = 1.0;

  this->CurrentState.DepthMask = GL_TRUE;

  this->CurrentState.Viewport[0] = 0;
  this->CurrentState.Viewport[1] = 0;
  this->CurrentState.Viewport[2] = 1;
  this->CurrentState.Viewport[3] = 1;

  this->CurrentState.Scissor[0] = 0;
  this->CurrentState.Scissor[1] = 0;
  this->CurrentState.Scissor[2] = 1;
  this->CurrentState.Scissor[3] = 1;

  this->CurrentState.CullFaceMode = GL_BACK;

  this->CurrentState.BlendEquationValue1 = GL_FUNC_ADD;
  this->CurrentState.BlendEquationValue2 = GL_FUNC_ADD;
}