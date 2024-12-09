void SoKnot::sogl_render_tube(const float radius,
			      const int segments,
			      const int nodes,
			      const float Tol,
			      SoMaterialBundle * const material,
			      const unsigned int flagsin,
			      SoState * state)
{

  // if segments or nodes changed, update the mesh
  if (_old_radius!=radius) {
    if (segments!=_old_segments || nodes!=_old_nodes) {

      knot->clear_tube();
      knot->flush_all();

      *knot = *original;
      if (original->isClosed())
        knot->link();

      knot->makeMesh(nodes,segments,radius,Tol);

      _old_segments = segments;
      _old_nodes = nodes;
    }
    else {
      knot->scaleTubeRadius(radius);
    }
    _old_radius = radius;
  }
  else {
    if (segments!=_old_segments || nodes!=_old_nodes) {
      knot->clear_tube();
      knot->flush_all();

      *knot = *original;

      if (flagsin & SOGL_NEED_TEXCOORDS)
        reset_texcoords(segments, nodes);

      if (original->isClosed()) knot->link();

      knot->makeMesh(nodes,segments,radius,Tol);

      _old_segments = segments;
      _old_nodes = nodes;

    }
  }

  // code in the sample inventor cube render thing
  //const SbBool * unitenabled = NULL;
  //int maxunit = 0;
  //const cc_glglue * glue = NULL;
  
  int flags = flagsin;

  /*
  if (state) {
    unitenabled = 
      SoMultiTextureEnabledElement::getEnabledUnits(state, maxunit);
    if (unitenabled) {
      glue = sogl_glue_instance(state);
      flags |= SOGL_NEED_MULTITEXCOORDS;
    }
    else maxunit = -1;
  }
*/

  int S = segments;
  int N = knot->isClosed()?nodes:nodes-1;

  //  int u;
  material->sendFirst();
  glBegin(GL_QUADS);

  for (int j=0;j<N;j++) { // number of nodes on the curve

    if (flags & SOGL_MATERIAL_PER_PART)
      material->forceSend(j); //, TRUE);

    for (int i=0;i<S;i++) { // number of segments on the circle

      // 4 corners of the quad
      // corner 1
      if (flags & SOGL_NEED_NORMALS)
	glNormal3fv((const GLfloat*)&(knot->meshNormal(j*(S+1)+i)));
      if (flags & SOGL_NEED_TEXCOORDS) {
	glTexCoord2fv(&sogl_tube_texcoords[2*(j*(S+1)+i)]);
      }
      /*
      else if (flags & SOGL_NEED_3DTEXCOORDS) {
	//glTexCoord3fv(sogl_cube_3dtexcoords[*iptr]);
	}*/
      /*
      if (flags & SOGL_NEED_MULTITEXCOORDS) {
	for (u = 1; u <= maxunit; u++) {
	  if (unitenabled[u]) {
	    //cc_glglue_glMultiTexCoord2fv(glue, (GLenum) (GL_TEXTURE0 + u),
	    //                               &sogl_cube_texcoords[j<<1]);
	  }
	}
      }
      */
      glVertex3fv((const GLfloat*)&(knot->meshPoint(j*(S+1)+i)));
      
      // corner 2
      if (flags & SOGL_NEED_NORMALS)
	glNormal3fv((const GLfloat*)&(knot->meshNormal((j+1)*(S+1)+i)));
      if (flags & SOGL_NEED_TEXCOORDS) {
	glTexCoord2fv(&sogl_tube_texcoords[2*((j+1)*(S+1)+i)]);
      }
      glVertex3fv((const GLfloat*)&(knot->meshPoint((j+1)*(S+1)+i)));

      // corner 3
      if (flags & SOGL_NEED_NORMALS)
	glNormal3fv((const GLfloat*)&(knot->meshNormal((j+1)*(S+1)+i+1)));
      if (flags & SOGL_NEED_TEXCOORDS) {
	glTexCoord2fv(&sogl_tube_texcoords[2*((j+1)*(S+1)+(i+1))]);
      }
      glVertex3fv((const GLfloat*)&(knot->meshPoint((j+1)*(S+1)+i+1)));

      // corner 4
      if (flags & SOGL_NEED_NORMALS)
	glNormal3fv((const GLfloat*)&(knot->meshNormal(j*(S+1)+i+1)));
      if (flags & SOGL_NEED_TEXCOORDS) {
	glTexCoord2fv(&sogl_tube_texcoords[2*(j*(S+1)+i+1)]);
      }
      glVertex3fv((const GLfloat*)&(knot->meshPoint(j*(S+1)+i+1)));

    }
  }
  glEnd();

  /* state stuff that i'm not familiar with so far 
  if (state) {
    // always encourage auto caching for cubes
    SoGLCacheContextElement::shouldAutoCache(state, SoGLCacheContextElement::DO_AUTO_CACHE);
  }
*/
}