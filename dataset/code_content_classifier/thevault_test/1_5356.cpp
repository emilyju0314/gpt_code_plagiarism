bool ts::UDPSocket::addMembership(const IPAddress& multicast, const IPAddress& local, const IPAddress& source, Report& report)
{
    // Verbose message about joining the group.
    UString groupString;
    if (source.hasAddress()) {
        groupString = source.toString() + u"@";
    }
    groupString += multicast.toString();
    if (local.hasAddress()) {
        report.verbose(u"joining multicast group %s from local address %s", {groupString, local});
    }
    else {
        report.verbose(u"joining multicast group %s from default interface", {groupString});
    }

    // Now join the group.
    if (source.hasAddress()) {
        // Source-specific multicast (SSM).
        SSMReq req(multicast, local, source);
        if (::setsockopt(getSocket(), IPPROTO_IP, IP_ADD_SOURCE_MEMBERSHIP, TS_SOCKOPT_T(&req.data), sizeof(req.data)) != 0) {
            report.error(u"error adding SSM membership to %s from local address %s: %s", {groupString, local, SocketErrorCodeMessage()});
            return false;
        }
        else {
            _ssmcast.insert(req);
            return true;
        }
    }
    else {
        // Standard multicast.
        MReq req(multicast, local);
        if (::setsockopt(getSocket(), IPPROTO_IP, IP_ADD_MEMBERSHIP, TS_SOCKOPT_T(&req.data), sizeof(req.data)) != 0) {
            report.error(u"error adding multicast membership to %s from local address %s: %s", {groupString, local, SocketErrorCodeMessage()});
            return false;
        }
        else {
            _mcast.insert(req);
            return true;
        }
    }
}