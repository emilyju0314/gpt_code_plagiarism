std::vector<Geom_Ptr> LavaVu::getGeometry(DrawingObject* target)
{
  //Gets data from active (geom) - includes fixed data, set timestep first to get time varying
  std::vector<Geom_Ptr> list;
  if (!amodel || !target) return list;
  for (auto g : amodel->geometry)
  {
    std::vector<Geom_Ptr> geomlist = g->getAllObjects(target);
    list.insert(std::end(list), std::begin(geomlist), std::end(geomlist));
  }
  return list;
}