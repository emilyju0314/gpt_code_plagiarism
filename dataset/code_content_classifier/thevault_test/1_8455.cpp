void glut_display() {
  glDisable(GL_BLEND);

  camera_->update();

  //render collision sphere
  if(effect_->m_sphere) {
    sphere_->set_translate(effect_->m_spherePos);
    sphere_->set_scale(effect_->m_sphereRad * 0.95);

    object_shader_->activate();

    glUniformMatrix4fv(object_shader_->getUniform(MODEL_MAT), 1, GL_FALSE, sphere_->get_model_matrix());
    glUniformMatrix4fv(object_shader_->getUniform(CAM_MAT), 1, GL_FALSE, glm::value_ptr(camera_->getViewMatrix()));
    glUniformMatrix4fv(object_shader_->getUniform(PROJ_MAT), 1, GL_FALSE,
                       glm::value_ptr(camera_->getProjectionMatrix()));
    glUniform4fv(object_shader_->getUniform(IN_COL), 1, glm::value_ptr(glm::vec4(0.f)));

    sphere_->draw();
    object_shader_->deactivate();
  }

  //render collision cube
  if(effect_->m_cube) {
    object_shader_->activate();

    cube_->set_translate(effect_->m_cubePos);
    cube_->set_scale(effect_->m_cubeDim);

    glUniformMatrix4fv(object_shader_->getUniform(MODEL_MAT), 1, GL_FALSE, cube_->get_model_matrix());
    glUniformMatrix4fv(object_shader_->getUniform(CAM_MAT), 1, GL_FALSE, glm::value_ptr(camera_->getViewMatrix()));
    glUniformMatrix4fv(object_shader_->getUniform(PROJ_MAT), 1, GL_FALSE,
                       glm::value_ptr(camera_->getProjectionMatrix()));
    glUniform4fv(object_shader_->getUniform(IN_COL), 1, glm::value_ptr(glm::vec4(0.f)));

    cube_->draw();
    object_shader_->activate();
  }

  //render fixed particles as spheres
  if(gui_mode_ == GUI_FIX || show_fixed_ || gui_mode_ == GUI_DRAG){
    glLineWidth(0.5f);
    object_shader_->mDrawMode = GL_LINE;
    object_shader_->activate();
    sphere_->set_scale(effect_->m_gridD / 2.f);
    glUniformMatrix4fv(object_shader_->getUniform(CAM_MAT), 1, GL_FALSE, glm::value_ptr(camera_->getViewMatrix()));
    glUniformMatrix4fv(object_shader_->getUniform(PROJ_MAT), 1, GL_FALSE,
                       glm::value_ptr(camera_->getProjectionMatrix()));
    glUniform4fv(object_shader_->getUniform(IN_COL), 1, glm::value_ptr(glm::vec4(0.8f, 0.f, 0.f, 1.f)));

    auto fixed = effect_->getfixedParticles();
    for(auto const& pos : fixed){
      sphere_->set_translate(pos);
      glUniformMatrix4fv(object_shader_->getUniform(MODEL_MAT), 1, GL_FALSE, sphere_->get_model_matrix());
      sphere_->draw();
    }

    object_shader_->deactivate();

  }

  glPointSize(3.f);
  glLineWidth(2.f);
  cloth_shader_->activate();
  //upload all uniforms
  glUniformMatrix4fv(cloth_shader_->getUniform(CAM_MAT), 1, GL_FALSE, glm::value_ptr(camera_->getViewMatrix()));
  glUniformMatrix4fv(cloth_shader_->getUniform(PROJ_MAT), 1, GL_FALSE, glm::value_ptr(camera_->getProjectionMatrix()));
  glUniformMatrix4fv(cloth_shader_->getUniform(NORM_MAT), 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(camera_->getViewMatrix()))));
  glUniform1i(cloth_shader_->getUniform(COLOR_MODE), color_mode_);
  glUniform3fv(cloth_shader_->getUniform(AMB), 1, glm::value_ptr(amb_));
  glUniform3fv(cloth_shader_->getUniform(DIFF), 1, glm::value_ptr(diff_));
  glUniform3fv(cloth_shader_->getUniform(SPEC), 1, glm::value_ptr(spec_));
  glUniform3fv(cloth_shader_->getUniform(SUN), 1, glm::value_ptr(sun_ * 1000.f));
  glUniform1i(cloth_shader_->getUniform(TEX), (current_tex_ + 1));
  //update parameters set by gui
  effect_->update(0.f);
  //update particle system
  if(gui_mode_ == GUI_STD || gui_mode_ == GUI_DRAG)effect_ ->cpuUpdate(16.f/1000.f);
  effect_ ->gpuUpdate();
  effect_ ->render();
  cloth_shader_->deactivate();
  //unbind, unuse
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glUseProgram(0);
  glEnable(GL_BLEND);

}