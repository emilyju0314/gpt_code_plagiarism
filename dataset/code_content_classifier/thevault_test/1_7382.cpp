bool p2p::isLocalHostAddress(bi::address const& _addressToCheck)
{
    // @todo: ivp6 link-local adresses (macos), ex: fe80::1%lo0
    static const set<bi::address> c_rejectAddresses = {
        {bi::address_v4::from_string("127.0.0.1")},
        {bi::address_v4::from_string("0.0.0.0")},
        {bi::address_v6::from_string("::1")},
        {bi::address_v6::from_string("::")}
    };
    
    return find(c_rejectAddresses.begin(), c_rejectAddresses.end(), _addressToCheck) != c_rejectAddresses.end();
}