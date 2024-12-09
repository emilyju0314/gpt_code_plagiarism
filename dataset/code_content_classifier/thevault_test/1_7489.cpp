void SoKnot::GLRender(SoGLRenderAction * action) {

  /* fixme : do that stuff for MBINDING==PER_VERTEX in order to mak
     curvature,torsion stuff working with this
     so far nothing is implemented in that direction
  */

  if (!this->shouldGLRender(action)) return;

  SoState * state = action->getState();

  SoMaterialBundle mb(action);
//  mb.sendFirst();

  SbBool doTextures = FALSE;
  SbBool do3DTextures = FALSE;
  if (SoGLTextureEnabledElement::get(state)) doTextures = TRUE;
  /*
  else if (SoGLTexture3EnabledElement::get(state)) do3DTextures = TRUE;
  */

  // urspruenglich :
  //SbBool sendNormals = !mb.isColorOnly() || 
  //  (SoTextureCoordinateElement::getType(state) == SoTextureCoordinateElement::FUNCTION);

  SbBool sendNormals = !mb.isColorOnly();  

  //float complexity = SbClamp(this->getComplexityValue(action), 0.0f, 1.0f);

  unsigned int flags = 0;
  if (sendNormals) flags |= SOGL_NEED_NORMALS;
  if (doTextures) flags |= SOGL_NEED_TEXCOORDS;
  else if (do3DTextures) flags |= SOGL_NEED_3DTEXCOORDS;
  if (SoMaterialBindingElement::get(state)==SoMaterialBindingElement::PER_PART)
    flags |= SOGL_MATERIAL_PER_PART;

  float Tol = knot->isClosed()?1e-3:-1;

  if (sogl_tube_texcoords==NULL && doTextures) {
 //    cout << "reset_tex ... " << flush;
    reset_texcoords(knot->segments(),knot->nodes());
 //    cout << "done\n" << flush;
  }

  sogl_render_tube(this->radius.getValue(),
		   this->segments.getValue(),
		   this->nodes.getValue(),
		   Tol,
		   &mb,
		   flags, state);

}