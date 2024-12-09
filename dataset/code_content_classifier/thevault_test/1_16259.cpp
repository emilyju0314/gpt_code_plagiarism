void PovrayWriter::writeVertexVectors(ofstream& out, DataCollector<>& dataCollector)
    {
      // initialization and preparations
      Mesh* mesh = dataCollector.getMesh();
      DOFVector<std::list<VertexInfo>>* vertexInfos = dataCollector.getVertexInfos();
      DOFVector<std::list<VertexInfo>>::Iterator it(vertexInfos, USED_DOFS);

      // begin of vertex_vectors block
      out << "\tvertex_vectors {" << endl;
      int nVertices = mesh->getNumberOfVertices();
      out << "\t\t" << nVertices << "," << endl;

      // For all DOFs of vertices, write the coordinates.
      for (it.reset(); !it.end(); ++it)
      {
        // for all vertex infos of this DOF
        for (std::list<VertexInfo>::iterator it2 = it->begin(); it2 != it->end(); ++it2)
        {
          out << endl;
          // TODO: right implementation using STL vector/iterator
          out  << "\t\t<";
          WorldVector<double> coords;
          coords = it2->coords;
          for (int i = 0; i < Global::getGeo(WORLD); i++)
          {
            if (i > 0)
              out << ", ";

            out << std::scientific << coords[i];
          }
          for (int i = Global::getGeo(WORLD); i < 3; i++)
            out << ", 0.0";
          out << ">,";
        }
      }
      // undo last comma
      long pos = out.tellp(); //tells pos the actual stream position
      out.seekp(pos - 1);     //sets stream position -1
      out <<  endl;         //overwrites the las comma with space
      // end of vertex_vectors block
      out << "\t}" << endl;
    }