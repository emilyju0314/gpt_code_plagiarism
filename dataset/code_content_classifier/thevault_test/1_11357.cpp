void ReadStream::InitRequest(size_t begin_bytes,
                             CURL *ecurl,
                             curl_slist **slist) {
  // initialize the curl request
  std::vector<std::string> amz;
  std::string date = GetDateString();
  std::string signature = Sign(aws_key_, "GET", "", "", date, amz,
                               std::string("/") + path_.host + '/' + RemoveBeginSlash(path_.name));
  // generate headers
  std::ostringstream sauth, sdate, surl, srange;
  std::ostringstream result;
  sauth << "Authorization: AWS " << aws_id_ << ":" << signature;
  sdate << "Date: " << date;
  surl << "https://" << path_.host << ".s3.amazonaws.com" << '/'
       << RemoveBeginSlash(path_.name);
  srange << "Range: bytes=" << begin_bytes << "-";
  *slist = curl_slist_append(*slist, sdate.str().c_str());
  *slist = curl_slist_append(*slist, srange.str().c_str());
  *slist = curl_slist_append(*slist, sauth.str().c_str());
  ASSERT_TRUE(curl_easy_setopt(ecurl, CURLOPT_HTTPHEADER, *slist) == CURLE_OK);
  ASSERT_TRUE(curl_easy_setopt(ecurl, CURLOPT_URL, surl.str().c_str()) == CURLE_OK);
  ASSERT_TRUE(curl_easy_setopt(ecurl, CURLOPT_HTTPGET, 1L) == CURLE_OK);
  ASSERT_TRUE(curl_easy_setopt(ecurl, CURLOPT_HEADER, 0L) == CURLE_OK);
  ASSERT_TRUE(curl_easy_setopt(ecurl, CURLOPT_NOSIGNAL, 1) == CURLE_OK);
}