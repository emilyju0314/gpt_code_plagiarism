void PovrayWriter::writeFile(std::string filename)
    {
      ofstream out;
      out.open(filename.c_str(), ios::out);

      // delegate all the work to other subroutines
      writeHeader(out);
      writeIncludes(out);
      writeCamera(out);
      writeLight(out);
      writeTestStuff(out, *dataCollector);
      writeMesh2(out, *dataCollector);

      out.close();
    }