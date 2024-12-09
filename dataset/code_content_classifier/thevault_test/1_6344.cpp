Geom_Ptr LavaVu::arrayUChar(DrawingObject* target, unsigned char* array, int len, lucGeometryDataType type, int width, int height, int depth)
{
  if (!amodel || !target) return nullptr;
  Geometry* container = amodel->lookupObjectRenderer(target);
  Geom_Ptr p = nullptr;
  if (container)
  {
    if (type == lucRGBAData)
    {
      int len32 = len / 4;
      assert(len32*4 == len);
      p = container->read(target, len32, type, array, width, height, depth);
    }
    else
      p = container->read(target, len, type, array, width, height, depth);
    reloadObject(target);
  }
  else
    std::cerr << "Container not found for data type: " << GeomData::names[type] << ", object:" << target->name() << std::endl;
  return p;
}