bool ts::S2XSatelliteDeliverySystemDescriptor::getChannelXML(Channel& channel, DuckContext& duck, const xml::Element* element)
{
    UString orbit;
    Variable<uint8_t> stream;

    bool ok =
        element != nullptr &&
        element->getIntAttribute<uint64_t>(channel.frequency, u"frequency", true) &&
        element->getIntAttribute<uint64_t>(channel.symbol_rate, u"symbol_rate", true) &&
        element->getAttribute(orbit, u"orbital_position", true) &&
        element->getIntEnumAttribute(channel.east_not_west, SatelliteDeliverySystemDescriptor::DirectionNames, u"west_east_flag", true) &&
        element->getIntEnumAttribute(channel.polarization, SatelliteDeliverySystemDescriptor::PolarizationNames, u"polarization", true) &&
        element->getIntEnumAttribute(channel.roll_off, RollOffNames, u"roll_off", true) &&
        element->getOptionalIntAttribute<uint8_t>(stream, u"input_stream_identifier");

    if (ok) {
        channel.multiple_input_stream_flag = stream.set();
        channel.input_stream_identifier = stream.value(0);

        // Expected orbital position is "XX.X" as in "19.2".
        uint16_t o1, o2;
        ok = orbit.scan(u"%d.%d", {&o1, &o2});
        if (ok) {
            channel.orbital_position = (o1 * 10) + o2;
        }
        else {
            element->report().error(u"Invalid value '%s' for attribute 'orbital_position' in <%s> at line %d, use 'nn.n'", {orbit, element->name(), element->lineNumber()});
        }
    }

    return ok;
}