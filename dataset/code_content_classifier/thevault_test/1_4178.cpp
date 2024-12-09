static void recompileAndReload()
{
  std::string cmd = "make lib";
  system(cmd.c_str());
  reload();
}