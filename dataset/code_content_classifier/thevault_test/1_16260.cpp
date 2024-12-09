void PovrayWriter::writeTextureList(ofstream& out, DataCollector<>& dataCollector)
    {
      // prepare some data structures
      Mesh* mesh = dataCollector.getMesh();
      DOFVector<std::list<VertexInfo>>* vertexInfos = dataCollector.getVertexInfos();
      DOFVector<std::list<VertexInfo>>::Iterator it(vertexInfos, USED_DOFS);


      // begin of texture_list block
      out << "\ttexture_list {" << endl;

      // compute and write the number of textures/colors (one for each vertex)
      int nTextures = mesh->getNumberOfVertices();
      out << "\t\t" << nTextures << "," << endl;

      // For all DOFs of vertices, write the coordinates.
      for (it.reset(); !it.end(); ++it)
      {
        // for all vertex infos of this DOF
        for (std::list<VertexInfo>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
        {
          // test: use y-coordinate to compute color
          double redValue = it2->coords[1];
          redValue = std::max(0., redValue);
          redValue = std::min(redValue, 1.);

          out << "\n\t\ttexture{ pigment{ rgb"<< getColorString(redValue) <<" } }" << ",";
        }
      }
      long pos = out.tellp();
      out.seekp(pos - 1);
      out << endl;
      // end of texture_list block
      out << "\t}" << endl;
    }