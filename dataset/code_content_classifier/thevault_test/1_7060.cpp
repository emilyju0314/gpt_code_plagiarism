void fetch_device_info(const std::string &url, ssdp_info_t *info)
{
  CURL *curl = curl_easy_init();
  char *ip;

  if (!curl) {
    fprintf(stderr, "curl_easy_init failed\n");
    return;
  }
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_PATH_AS_IS, 1L);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, info);
  curl_easy_setopt(curl, CURLOPT_USERAGENT, "ssdptaxonomy/1.0");
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1L);
  curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
  if (curl_easy_perform(curl) == CURLE_OK) {
    extract_fields_from_buffer(info);
  } else {
    info->failed = 1;
  }
  if (curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &ip) == CURLE_OK) {
    info->ipaddr = ip;
  }

  info->buffer.clear();
  curl_easy_cleanup(curl);
}