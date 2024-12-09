void ts::VCT::Channel::setService(Service& service) const
{
    service.setId(program_number);
    service.setTSId(channel_TSID);
    service.setName(short_name);
    service.setMajorIdATSC(major_channel_number);
    service.setMinorIdATSC(minor_channel_number);
    service.setTypeATSC(service_type);
    service.setCAControlled(access_controlled);
}