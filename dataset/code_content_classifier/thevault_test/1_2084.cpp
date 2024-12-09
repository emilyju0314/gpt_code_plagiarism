void SmokeRenderer::calcVectors()
{
    // get model view matrix
    glGetFloatv(GL_MODELVIEW_MATRIX, (float *) m_modelView.get_value());

    // calculate eye space light vector
    m_lightVector = normalize(m_lightPos);
    m_lightPosEye = m_modelView * vec4f(m_lightPos, 1.0);

    // calculate half-angle vector between view and light
    m_viewVector = -vec3f(m_modelView.get_row(2));
    if (dot(m_viewVector, m_lightVector) > 0) {
        m_halfVector = normalize(m_viewVector + m_lightVector);
        m_invertedView = false;
    } else {
        m_halfVector = normalize(-m_viewVector + m_lightVector);
        m_invertedView = true;
    }

    // calculate light view matrix
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    gluLookAt(m_lightPos[0], m_lightPos[1], m_lightPos[2], 
              m_lightTarget[0], m_lightTarget[1], m_lightTarget[2],
              0.0, 1.0, 0.0);

    // calculate light projection matrix
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 200.0);

    glGetFloatv(GL_MODELVIEW_MATRIX, (float *) m_lightView.get_value());
    glGetFloatv(GL_PROJECTION_MATRIX, (float *) m_lightProj.get_value());

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    // construct shadow matrix
    matrix4f scale;
    scale.set_scale(vec3f(0.5, 0.5, 0.5));
    matrix4f translate;
    translate.set_translate(vec3f(0.5, 0.5, 0.5));

    m_shadowMatrix = translate * scale * m_lightProj * m_lightView * inverse(m_modelView);

    // calc object space eye position
    m_eyePos = inverse(m_modelView) * vec4f(0.0, 0.0, 0.0, 1.0);

    // calc half vector in eye space
    m_halfVectorEye = m_modelView * vec4f(m_halfVector, 0.0);
}