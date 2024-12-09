void PovrayWriter::writeLight(ofstream& out)
    {
      // TODO: compute adequate light position
      out << "light_source { <0, 0, -15> color White}" << endl;
    }