void PovrayWriter::writeTestStuff(ofstream& out, DataCollector<>& dataCollector)
    {
      Mesh* mesh = dataCollector.getMesh();

      out << "/*" << endl;
      out << "TestData:" << endl;

      int dow = Global::getGeo(WORLD);
      out << " world dimension:\t" << dow << endl;

      out << " dimension:\t" << mesh->getDim() << endl;
      out << " numberOfNodes:\t" << mesh->getNumberOfNodes() << endl;
      out << " numberOfEdges:\t" << mesh->getNumberOfEdges() << endl;
      out << " numberOfVertices:\t" << mesh->getNumberOfVertices() << endl;
      out << " numberOfFaces:\t" << mesh->getNumberOfFaces() << endl;
      out << " numberOfElements:\t" << mesh->getNumberOfElements() << endl;
      out << "*/" << endl << endl;
    }