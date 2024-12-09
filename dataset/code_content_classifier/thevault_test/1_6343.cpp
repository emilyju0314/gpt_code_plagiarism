bool LavaVu::loadModelStep(int model_idx, int at_timestep, bool autozoom)
{
  GL_Check_Thread(viewer->render_thread);
  if (models.size() == 0) defaultModel();
  if (model_idx < 0 || model_idx >= (int)models.size()) return false;

  //Save active model as selected
  amodel = models[model_idx];

  //No change? Skip loading
  if (model_idx == model && at_timestep >= 0 && at_timestep == session.now) return false;

  model = model_idx;

  //Save active colourmaps list on session
  session.colourMaps = amodel->colourMaps;

  //Have a database model loaded already?
  if (amodel->objects.size() > 0)
  {
    //Redraw model data
    amodel->redraw();

    //Set timestep and load geometry at that step
    if (amodel->database)
    {
      if (at_timestep < 0)
        amodel->setTimeStep(session.now);
      else
        amodel->setTimeStep(amodel->nearestTimeStep(at_timestep));
      if (verbose) std::cerr << "Loading vis '" << session.global("caption") << "', timestep: " << amodel->step() << std::endl;
    }
  }

  if (!aview) aview = amodel->views[0];

  json res = session.global("resolution");

  //Not yet opened or resized?
  if (!viewer->isopen)
    //Open window at required size
    viewer->open(res[0], res[1]);
  else
    //Resize if necessary
    viewer->setsize(res[0], res[1]);

  //Flag a view update
  viewset = autozoom ? RESET_ZOOM : RESET_YES;
#ifdef __EMSCRIPTEN__
  //We lose the global "resolution" property when new model loaded, so reset
  //EM_ASM({window.resized = true;});
#endif
  return true;
}