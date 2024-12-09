const std::string unfriendly_name(const std::string &manufacturer,
    const std::string &model)
{
  if (strcasestr(model.c_str(), manufacturer.c_str()) != NULL) {
    return model;
  }

  return manufacturer + " " + model;
}