bool BaseSitemapService::EndGenerating(bool alwaysindex, bool noindex) {
  if (alwaysindex && noindex) {
    Logger::Log(EVENT_ERROR, "always-index and always-no-index conflicted.");
    return false;
  }

  // A flag indicating whether there is no url given by AddUrl.
  bool no_url = sitemap_index_.Size() == 0 && urlset_.Size() == 0;

  // Write all the left urls to sitemap file,
  // or if there is no url processed, and always index is false,
  // an empty sitemap should be generated.
  if (urlset_.Size() > 0 || (no_url && !alwaysindex)) {
    // Maybe we should write more than one time to flush all values.
    do {
      if (!Flush()) {
        return false;
      }
    } while (urlset_.Size() > 0);
  }

  // The final sitemap file name, which should be used to inform search engine.
  std::string final_file = BuildPath(-1, true);

  if ((sitemap_index_.Size() > 1 && noindex == false) || alwaysindex) {
    // A sitemap index file should be generated.

    // Compress all sitemap files.
    if (sitemapsetting_->compress()) {
      for (int i = 0; i < sitemap_index_.Size(); ++i) {
        std::string sitemap_file = BuildPath(i, true);
        CompressFile(sitemap_file.c_str());
      }
    }

    // Create the sitemap index file with "final_file" as its name.
    int result = writer_->WriteSitemapIndex(final_file, sitemap_index_);
    if (result == 0) {
      if (sitemapsetting_->compress()) {
        return CompressFile(final_file);
      } else {
        return true;
      }
    } else {
      Logger::Log(EVENT_ERROR, "Failed to create sitemap index [%s] for [%s].",
        final_file.c_str(), sitesetting_.site_id().c_str());
      return false;
    }

  } else if ((sitemap_index_.Size() == 1 && alwaysindex == false) || noindex) {
    // No sitemap index file should be generated.

    // When there is more than one sitemap, only sitemap-0 should be saved.
    if (sitemap_index_.Size() > 1) {
      for (int i = 1; i < sitemap_index_.Size(); ++i) {
        std::string sitemap_i = BuildPath(i, true);
        remove(sitemap_i.c_str());
      }
    }

    // Rename sitemap-0 to the final sitemap file name.
    std::string sitemap0 = BuildPath(0, true);
    remove(final_file.c_str());  // Try to remove destination file.
    if (rename(sitemap0.c_str(), final_file.c_str()) != 0) {
      Logger::Log(EVENT_ERROR, "Failed to rename file [%s] to [%s] (%d)\n",
                sitemap0.c_str(), final_file.c_str(), errno);
      return false;
    }

    // Compress the final sitemap file.
    if (sitemapsetting_->compress()) {
      return CompressFile(final_file);
    } else {
      return true;
    }
  } else {
    // Logic never comes here. Just for compiler.
    return true;
  }
}