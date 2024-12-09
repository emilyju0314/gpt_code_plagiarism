void PovrayWriter::writeIncludes(ofstream& out)
    {
      out << "#include \"colors.inc\"" << endl;
      out << "#include \"stones.inc\"" << endl;
      out << endl;
    }