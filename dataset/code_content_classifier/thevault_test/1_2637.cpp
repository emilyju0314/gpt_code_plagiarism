DataFileEngineXml::
DataFileEngineXml(const std::string& filename, bool throw_exceptions)
  : throw_exceptions_(throw_exceptions)
{
  //  LOG << "Reading " << filename << "\n";
  xml_load_config_file(filename.c_str());
  filename_ = filename;
}