bool IPNet :: contains(IP ipNew) {
    std::pair<IP, IPMask> p = networkNumberAndMask(*this);
    IP x;
    x = ipNew.To4();
    if(x.isLegal == true) {
        ipNew = x;
    }
    int l = int(ipNew.ip.size());
    if(l != p.first.ip.size()) {
        return false;
    }
    for(int i = 0 ; i < l ; i++) {
        if((p.first.ip[i]&p.second[i]) != (ipNew.ip[i]&p.second[i])) {
            return false;
        }
    }
    return true;
}