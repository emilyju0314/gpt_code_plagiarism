Subscription* Subscription_serializer::to_object (std::string const& source)
{
    vstring_t parts = split(source, delimeter_);
    if (parts.size() < 8) {
        return nullptr;
    }
    
    auto subs = new Subscription;
    subs->id_ = std::stoi(parts[0]);
    subs->name = parts[1];
    subs->type = parts[2];
    subs->unit_title = parts[3];
    subs->max_unit_count = std::stoi(parts[4]);
    if (!parts[5].empty()) {
        subs->effective_to = &date_time::parse(parts[5]);
    }
    if (!parts[6].empty()) {
        subs->effective_to = &date_time::parse(parts[6]);
    }
    subs->hours = std::stoi(parts[7]);
    
    return subs;
}