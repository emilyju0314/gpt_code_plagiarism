bool contains_email_address(const std::string &friendlyName)
{
  regex_t r_email;
  int rc;

  if (regcomp(&r_email, ".+@[a-z0-9.-]+\\.[a-z0-9.-]+",
        REG_EXTENDED | REG_ICASE | REG_NOSUB)) {
    fprintf(stderr, "%s: regcomp failed!\n", __FUNCTION__);
    exit(1);
  }

  rc = regexec(&r_email, friendlyName.c_str(), 0, NULL, 0);
  regfree(&r_email);

  return (rc == 0);
}