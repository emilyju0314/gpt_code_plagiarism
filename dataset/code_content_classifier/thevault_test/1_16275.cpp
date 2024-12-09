inline
    void readFile(std::string filename,
                  Mesh* mesh)
    {

      std::string ext = filename.substr(filename.find_last_of("."));
      if (ext == ".1d" || ext == ".2d" || ext == ".3d")
      {
        std::string periodicFilename = "";
        int check = 1;
        Parameters::get(mesh->getName() + "->periodic file", periodicFilename);
        Parameters::get(mesh->getName() + "->check", check);
        MacroReader::readMacro(filename, mesh, periodicFilename, check);
      }
      else if (ext == ".arh")
      {
//         if (Arh2Reader::isReadable(filename))
//           Arh2Reader::readFile(filename, mesh);
        TEST_EXIT(Arh3Reader::isReadable(filename))("File is not in ARH3 format. Please convert!\n");
        Arh3Reader::readFile(filename, mesh);
//         else
//           ArhReader::readFile(filename, mesh);
      }
      else
      {
        ERROR_EXIT("File-extensions %s can not be assigned to a reader!\n", ext.c_str());
      }
    }