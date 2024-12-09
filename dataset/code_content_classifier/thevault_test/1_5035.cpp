uint8_t ts::SDT::Service::serviceType(DuckContext& duck) const
{
    ServiceDescriptor sd;
    return locateServiceDescriptor(duck, sd) ? sd.service_type : 0; // 0 is a "reserved" service_type value
}