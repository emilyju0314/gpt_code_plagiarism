void PovrayWriter::writeMesh2(ofstream& out, DataCollector<>& dataCollector)
    {
      // initialization and preparations
      //Mesh *mesh = dataCollector.getMesh();

      // begin of mesh2 block
      out << "mesh2 {" << endl;

      // delegate work to other methods
      writeVertexVectors(out, dataCollector);
      //writeTextureList(out, dataCollector);
      tryMeshTraversal(out);
      writeFaceIndices(out, dataCollector);
      out << "\t" << "pigment {rgb 1}" << endl;
      // end of mesh2 block
      out << "}" << endl;
    }