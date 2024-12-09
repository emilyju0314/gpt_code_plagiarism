bool ts::CADescriptor::fromCommmandLine(const UString& value, Report& report)
{
    private_data.clear();

    int casid = 0;
    int pid = 0;
    size_t count = 0;
    size_t index = 0;

    value.scan(count, index, u"%i/%i", {&casid, &pid});

    // On return, index points to the next index in val after "cas-id/PID".
    // If there is a private part, then index must points to a '/'.
    if (count != 2 || casid < 0 || casid > 0xFFFF || pid < 0 || pid >= int(PID_MAX) || (index < value.length() && value[index] != u'/')) {
        report.error(u"invalid \"cas-id/PID[/private-data]\" value \"%s\"", {value});
        return false;
    }

    cas_id = uint16_t(casid);
    ca_pid = PID(pid);

    if (index < value.length()) {
        // There is a private part
        const UString hexa(value.substr(index + 1));
        if (!hexa.hexaDecode(private_data)) {
            report.error(u"invalid private data \"%s\" for CA_descriptor, specify an even number of hexa digits", {hexa});
            return false;
        }
    }

    return true;
}