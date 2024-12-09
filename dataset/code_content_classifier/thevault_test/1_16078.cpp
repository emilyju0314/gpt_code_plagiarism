static int stun_get_mapped(struct stun_attr *attr, void *arg)
{
    struct stun_addr *addr = (struct stun_addr *)(attr + 1);
    struct sockaddr_in *sa = (struct sockaddr_in *)arg;
    int rc = 0;
    if(ntohs(attr->len) != 8)
        return rc;

    uint32_t xor_mask;

    switch(ntohs(attr->attr)) {
        case STUN_MAPPED_ADDRESS:
            if(sa->sin_addr.s_addr == 0) {
                rc = 1;
                xor_mask = 0;
            }
            break;
        case STUN_XORMAPPEDADDRESS:
            rc = 2;
            xor_mask = STUN_XORMAGIC;
            break;
        case STUN_XORMAPPEDADDRESS2:
            rc = 4;
            xor_mask = STUN_XORMAGIC;
            break;
        default: break;
    }

    if(rc) {
        sa->sin_port        = addr->port ^ xor_mask;
        sa->sin_addr.s_addr = addr->addr ^ xor_mask;
    }

    return rc;
}