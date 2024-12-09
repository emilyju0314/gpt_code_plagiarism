bool ts::UDPSocket::setBroadcastIfRequired(const IPAddress destination, Report& report)
{
    // Get all local interfaces.
    IPAddressMaskVector locals;
    if (!GetLocalIPAddresses(locals, report)) {
        return false;
    }

    // Loop on all local addresses and set broadcast when we match a local broadcast address.
    for (auto it = locals.begin(); it != locals.end(); ++it) {
        if (destination == it->broadcastAddress()) {
            return setBroadcast(true, report);
        }
    }

    // Not a broadcast address, nothing was done.
    return true;
}