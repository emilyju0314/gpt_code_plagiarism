BoundingBox* PovrayWriter::getBoundingBox(ofstream& /*out*/)
    {
      if (bBox != NULL)
        return bBox;

      DOFVector<std::list<VertexInfo>>* vertexInfos = dataCollector->getVertexInfos();
      DOFVector<std::list<VertexInfo>>::Iterator it(vertexInfos, USED_DOFS);
      int dow = Global::getGeo(WORLD);
      bBox = new BoundingBox();

      it.reset();
      std::list<VertexInfo>::iterator it2 = it->begin();
      bBox->minx = it2->coords[0];
      bBox->maxx = it2->coords[0];
      bBox->miny = it2->coords[1];
      bBox->maxy = it2->coords[1];
      if (dow == 3)
      {
        bBox->minz = it2->coords[2];
        bBox->maxz = it2->coords[2];
      }
      else
      {
        bBox->minz = bBox->maxz = 0;
      }

      for (it.reset(); !it.end(); ++it)
      {
        // initialize mit and max values with coordinates of first vertex
        std::list<VertexInfo>::iterator it2 = it->begin();
        bBox->minx = std::min(bBox->minx, it2->coords[0]);
        bBox->maxx = std::max(bBox->maxx, it2->coords[0]);
        bBox->miny = std::min(bBox->miny, it2->coords[1]);
        bBox->maxy = std::max(bBox->maxy, it2->coords[1]);
        if (dow == 3)
        {
          bBox->minz = std::min(bBox->minz, it2->coords[2]);
          bBox->maxz = std::max(bBox->maxz, it2->coords[2]);
        }
      }

      return bBox;
    }