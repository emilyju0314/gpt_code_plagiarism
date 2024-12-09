bool ts::UDPSocket::addMembershipAll(const IPAddress& multicast, const IPAddress& source, Report& report)
{
    // There is no implicit way to listen on all interfaces.
    // If no local address is specified, we must get the list
    // of all local interfaces and send a multicast membership
    // request on each of them.

    // Get all local interfaces.
    IPAddressVector loc_if;
    if (!GetLocalIPAddresses(loc_if, report)) {
        return false;
    }

    // Add all memberships
    bool ok = true;
    for (size_t i = 0; i < loc_if.size(); ++i) {
        if (loc_if[i].hasAddress()) {
            ok = addMembership(multicast, loc_if[i], source, report) && ok;
        }
    }
    return ok;
}