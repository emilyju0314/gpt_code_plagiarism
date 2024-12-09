std::string UrlElement::ToString() const {
  std::ostringstream ostrstream;
  ostrstream << "Url: "
    << "changefreq: " << changefreq_
    << "lastmod: " << lastmod_
    << "loc_: " << loc_
    << "priority_" << priority_;
  return ostrstream.str();
}