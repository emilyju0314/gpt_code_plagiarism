void LavaVu::resetViews(bool autozoom)
{
  //Copy active view state props to dictionary
  aview->exportProps();
  viewset = RESET_NO;

  //Setup view(s) for new model dimensions
  int curview = view;
  for (unsigned int v=0; v < amodel->views.size(); v++)
    viewSelect(v, true, autozoom);
  //Restore active
  viewSelect(curview);

  //Flag redraw required
  amodel->redraw();

  //Set viewer title
  std::stringstream title;
  std::string name = session.global("caption");
  std::string vptitle = aview->properties["title"];
  if (vptitle.length() > 0)
    title << vptitle;
  else
    title << "LavaVu";
  if (name.length() > 0)
    title << " (" << name << ")";

  if (amodel->timesteps.size() > 1)
    title << " - timestep " << std::setw(5) << std::setfill('0') << amodel->stepInfo();

  //Update title
  viewer->title(title.str());

  //Apply any prop changes to active view state
  aview->importProps();
}