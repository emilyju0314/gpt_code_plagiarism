bool Geometry::drawable(unsigned int idx)
{
  expandHidden();
  if (idx >= geom.size()) return false;
  if (!geom[idx]->draw->visible) return false;
  //Within bounds and not hidden
  if (geom[idx]->count() > 0 && !hidden[idx])
  {
    //Not filtered by viewport?
    if (!view->filtered) return true;

    //Search viewport object set
    if (view->hasObject(geom[idx]->draw))
      return true;

  }
  return false;
}