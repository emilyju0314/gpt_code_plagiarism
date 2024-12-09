Glyphs::Glyphs(Session& session) : Geometry(session)
{
  //Create sub-renderers
  //All renderers are switchable and user defined based on "glyphrenderlist" global property
  std::string renderlist = session.global("subrenderers");
  std::istringstream iss(renderlist);
  std::string s;
  while (getline(iss, s, ' '))
  {
    //Only support line/triangle/point primitive renderers)
    //(NOTE: Attempting to create a Glyphs renderer as sub-renderer will cause an infinite loop)
    //std::cout << "CREATING: " << s << std::endl;
    lucGeometryType prim = session.typeMap[s];
    if (prim == lucTriangleType)
      tris = (Triangles*)createRenderer(session, s);
    else if (prim == lucLineType)
      lines = (Lines*)createRenderer(session, s);
    else if (prim == lucPointType)
      points = (Points*)createRenderer(session, s);
  }

  //Placeholder null renderers
  if (!lines) lines = (Lines*)(new Geometry(session));
  if (!tris) tris = (Triangles*)(new Geometry(session));
  if (!points) points = (Points*)(new Geometry(session));

  tris->internal = lines->internal = points->internal = true;
}