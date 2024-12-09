IP IP :: To4() {
    if(ip.size() == IPv4len) {
        return *this;
    }
    IP ipNew;
    std::vector <byte> ipN (ip.begin(), ip.begin() + 10);
    ipNew.ip = ipN;
    if(ip.size() == IPv6len && isZeros(ipNew) && ip[10] == 0xff && ip[11] == 0xff) {
        IP ipNew2;
        std::vector <byte> ipN(ip.begin() + 12, ip.begin() + 16);
        ipNew2.ip = ipN;
        return ipNew2;
    }
    this->isLegal = false;
    return *this;
}