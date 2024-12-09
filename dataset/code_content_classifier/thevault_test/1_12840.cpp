inline std::string ParamString(const std::string& paramName)
{
  // Return the correct parameter name.
  if (CLI::Parameters().count(paramName) > 0)
  {
    util::ParamData& d = CLI::Parameters()[paramName];

    std::string output;
    CLI::GetSingleton().functionMap[d.tname]["GetPrintableParamName"](d, NULL,
        (void*) &output);
    // Is there an alias?
    std::string alias = "";
    if (d.alias != '\0')
      alias = " (-" + std::string(1, d.alias) + ")";

    return "'" + output + alias + "'";
  }
  else
  {
    throw std::runtime_error("Parameter '" + paramName + "' not known!  Check "
        "PROGRAM_INFO() definition.");
  }
}