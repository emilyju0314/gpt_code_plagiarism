std::string UrlElement::ConvertFrequencyToString(const UrlElement::ChangeFreq& changefreq) {
  switch (changefreq) {
    case UrlElement::ALWAYS:   return "always";
    case UrlElement::HOURLY:   return "hourly";
    case UrlElement::DAILY:    return "daily";
    case UrlElement::WEEKLY:   return "weekly";
    case UrlElement::MONTHLY:  return "monthly";
    case UrlElement::YEARLY:   return "yearly";
    case UrlElement::NEVER:    return "never";
    default:            return ""; // log error here!
  }
}