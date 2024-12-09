TSReturnCode
TSRemapNewInstance(int argc, char *argv[], void **ih, char * /* errbuf ATS_UNUSED */, int /* errbuf_size ATS_UNUSED */)
{
  static const struct option longopt[] = {
    {const_cast<char *>("access_key"), required_argument, nullptr, 'a'},
    {const_cast<char *>("config"), required_argument, nullptr, 'c'},
    {const_cast<char *>("secret_key"), required_argument, nullptr, 's'},
    {const_cast<char *>("version"), required_argument, nullptr, 'v'},
    {const_cast<char *>("virtual_host"), no_argument, nullptr, 'h'},
    {const_cast<char *>("v4-include-headers"), required_argument, nullptr, 'i'},
    {const_cast<char *>("v4-exclude-headers"), required_argument, nullptr, 'e'},
    {const_cast<char *>("v4-region-map"), required_argument, nullptr, 'm'},
    {const_cast<char *>("session_token"), required_argument, nullptr, 't'},
    {nullptr, no_argument, nullptr, '\0'},
  };

  S3Config *s3          = new S3Config(true); // true == this config gets the continuation
  S3Config *file_config = nullptr;

  // argv contains the "to" and "from" URLs. Skip the first so that the
  // second one poses as the program name.
  --argc;
  ++argv;

  while (true) {
    int opt = getopt_long(argc, static_cast<char *const *>(argv), "", longopt, nullptr);

    switch (opt) {
    case 'c':
      file_config = gConfCache.get(optarg); // Get cached, or new, config object, from a file
      if (!file_config) {
        TSError("[%s] invalid configuration file, %s", PLUGIN_NAME, optarg);
        *ih = nullptr;
        return TS_ERROR;
      }
      break;
    case 'a':
      s3->set_keyid(optarg);
      break;
    case 's':
      s3->set_secret(optarg);
      break;
    case 't':
      s3->set_token(optarg);
      break;
    case 'h':
      s3->set_virt_host();
      break;
    case 'v':
      s3->set_version(optarg);
      break;
    case 'i':
      s3->set_include_headers(optarg);
      break;
    case 'e':
      s3->set_exclude_headers(optarg);
      break;
    case 'm':
      s3->set_region_map(optarg);
      break;
    }

    if (opt == -1) {
      break;
    }
  }

  // Copy the config file secret into our instance of the configuration.
  if (file_config) {
    s3->copy_changes_from(file_config);
  }

  // Make sure we got both the shared secret and the AWS secret
  if (!s3->valid()) {
    TSError("[%s] requires both shared and AWS secret configuration", PLUGIN_NAME);
    *ih = nullptr;
    return TS_ERROR;
  }

  if (s3->expiration() == 0) {
    TSDebug(PLUGIN_NAME, "disabling auto config reload");
  } else {
    // auto reload is scheduled to be 5 minutes before the expiration time to get some headroom
    long time_diff = s3->expiration() -
                     std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if (time_diff > 0) {
      long delay = cal_reload_delay(time_diff);
      TSDebug(PLUGIN_NAME, "scheduling config reload with %ld seconds delay", delay);
      s3->reset_conf_reload_count();
      s3->schedule_conf_reload(delay);
    } else {
      TSDebug(PLUGIN_NAME, "config expiration time is in the past, re-checking in 1 minute");
      s3->schedule_conf_reload(60);
    }
  }

  *ih = static_cast<void *>(s3);
  TSDebug(PLUGIN_NAME, "New rule: access_key=%s, virtual_host=%s, version=%d", s3->keyid(), s3->virt_host() ? "yes" : "no",
          s3->version());

  return TS_SUCCESS;
}