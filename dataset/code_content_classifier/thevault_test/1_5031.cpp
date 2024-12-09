bool ts::SDT::findService(DuckContext& duck, const UString& name, uint16_t& service_id, bool exact_match) const
{
    for (ServiceMap::const_iterator it = services.begin(); it != services.end(); ++it) {
        const UString service_name(it->second.serviceName(duck));
        if ((exact_match && service_name == name) || (!exact_match && service_name.similar(name))) {
            service_id = it->first;
            return true;
        }
    }

    // Service not found
    service_id = 0;
    return false;
}