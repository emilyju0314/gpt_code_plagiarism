void checkAndUpdate(std::string const & livefile)
{
  struct stat fileStat;

  if (stat(livefile.c_str(), &fileStat) < 0)
    {
      std::cerr << "Couldn't stat file " << livefile << std::endl;
      return;
    }

  long currUpdateTime = fileStat.st_mtime;
  if (currUpdateTime != prevUpdateTime)
    {
      // std::cout << "#################################" << std::endl;
      // std::cout << "Compile reload" << std::endl;
      recompileAndReload();
    }
  prevUpdateTime = currUpdateTime;
}