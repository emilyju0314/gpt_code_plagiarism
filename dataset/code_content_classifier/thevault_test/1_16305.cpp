bool SignatureManager::LoadTrustedCaCrl(const string &path_list) {
  InitX509Store();

  /* TODO if (path_list == "") {
    return true;
  }*/
  const vector<string> paths = SplitString(path_list, ':');
  for (unsigned i = 0; i < paths.size(); ++i) {
    int retval = X509_LOOKUP_add_dir(x509_lookup_, paths[i].c_str(),
                                     X509_FILETYPE_PEM);
    if (!retval)
      return false;
  }
  return true;
}