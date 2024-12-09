S3Config *
ConfigCache::get(const char *fname)
{
  S3Config *s3;

  struct timeval tv;

  gettimeofday(&tv, nullptr);

  // Make sure the filename is an absolute path, prepending the config dir if needed
  std::string config_fname = makeConfigPath(fname);

  auto it = _cache.find(config_fname);

  if (it != _cache.end()) {
    unsigned update_status = it->second.update_status;
    if (tv.tv_sec > (it->second.load_time + _ttl)) {
      if (!(update_status & 1) && it->second.update_status.compare_exchange_strong(update_status, update_status + 1)) {
        TSDebug(PLUGIN_NAME, "Configuration from %s is stale, reloading", config_fname.c_str());
        s3 = new S3Config(false); // false == this config does not get the continuation

        if (s3->parse_config(config_fname)) {
          s3->set_conf_fname(fname);
        } else {
          // Failed the configuration parse... Set the cache response to nullptr
          delete s3;
          s3 = nullptr;
          TSAssert(!"Configuration parsing / caching failed");
        }

        delete it->second.config;
        it->second.config    = s3;
        it->second.load_time = tv.tv_sec;

        // Update is complete.
        ++it->second.update_status;
      } else {
        // This thread lost the race with another thread that is also reloading
        // the config for this file. Wait for the other thread to finish reloading.
        while (it->second.update_status & 1) {
          // Hopefully yielding will sleep the thread at least until the next
          // scheduler interrupt, preventing a busy wait.
          std::this_thread::yield();
        }
        s3 = it->second.config;
      }
    } else {
      TSDebug(PLUGIN_NAME, "Configuration from %s is fresh, reusing", config_fname.c_str());
      s3 = it->second.config;
    }
  } else {
    // Create a new cached file.
    s3 = new S3Config(false); // false == this config does not get the continuation

    TSDebug(PLUGIN_NAME, "Parsing and caching configuration from %s, version:%d", config_fname.c_str(), s3->version());
    if (s3->parse_config(config_fname)) {
      s3->set_conf_fname(fname);
      _cache.emplace(config_fname, _ConfigData(s3, tv.tv_sec));
    } else {
      delete s3;
      s3 = nullptr;
      TSAssert(!"Configuration parsing / caching failed");
    }
  }
  return s3;
}