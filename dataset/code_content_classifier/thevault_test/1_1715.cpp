void VideoSitemapService::ConvertRecord(const VisitingRecord &record,
                                        UrlElement* url) {
  std::string location(host_);
  location.append(record.url());
  url->set_loc(location);
}