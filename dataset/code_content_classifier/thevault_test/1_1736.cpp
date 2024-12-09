bool BaseSitemapService::AddUrl(const UrlElement &url) {
  ++urls_count_;
  urlset_.AddUrl(url);

  // Url number meets limit, so they should be written to a file
  if (sitemapsetting_->max_file_url_number() > 0
      && urlset_.Size() >= sitemapsetting_->max_file_url_number()) {
    return Flush();
  }

  return true;
}