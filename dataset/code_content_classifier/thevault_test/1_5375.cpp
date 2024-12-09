void ts::S2XSatelliteDeliverySystemDescriptor::buildChannelXML(const Channel& channel, xml::Element* parent, const UString& name) const
{
    xml::Element* e = parent->addElement(name);
    e->setIntAttribute(u"frequency", channel.frequency, false);
    e->setAttribute(u"orbital_position", UString::Format(u"%d.%d", {channel.orbital_position / 10, channel.orbital_position % 10}));
    e->setIntEnumAttribute(SatelliteDeliverySystemDescriptor::DirectionNames, u"west_east_flag", channel.east_not_west);
    e->setIntEnumAttribute(SatelliteDeliverySystemDescriptor::PolarizationNames, u"polarization", channel.polarization);
    e->setIntEnumAttribute(RollOffNames, u"roll_off", channel.roll_off);
    e->setIntAttribute(u"symbol_rate", channel.symbol_rate, false);
    if (channel.multiple_input_stream_flag) {
        e->setIntAttribute(u"input_stream_identifier", channel.input_stream_identifier, true);
    }
}