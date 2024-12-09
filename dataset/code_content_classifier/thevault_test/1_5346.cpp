void ts::Service::set(const UString& desc)
{
    clear();

    uint16_t id = 0;
    uint16_t minor = 0;

    if (desc.toInteger(id)) {
        // Found a service id.
        _id = id;
    }
    else if (desc.scan(u"%d.%d", {&id, &minor})) {
        // Found an ATSC major.minor id.
        _major_id_atsc = id;
        _minor_id_atsc = minor;
    }
    else if (!desc.empty()) {
        // Finally, just a service name.
        _name = desc;
    }
}