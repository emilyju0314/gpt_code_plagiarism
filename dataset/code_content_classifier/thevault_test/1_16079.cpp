static int stun_handle_packet(int s, struct sockaddr_in *src,
                              unsigned char *data, size_t len, void *arg)
{
    struct stun_header *hdr = (struct stun_header *)data;
    struct stun_attr *attr;
    int ret = 0;
    size_t x;

    /* On entry, 'len' is the length of the udp payload. After the
     * initial checks it becomes the size of unprocessed options,
     * while 'data' is advanced accordingly.
     */
    if (len < sizeof(struct stun_header))
        return -20;

    len -= sizeof(struct stun_header);
    data += sizeof(struct stun_header);
    x = ntohs(hdr->msglen);	/* len as advertised in the message */
    if(x < len)
        len = x;

    while (len) {
        if (len < sizeof(struct stun_attr)) {
            ret = -21;
            break;
        }
        attr = (struct stun_attr *)data;
        /* compute total attribute length */
        x = ntohs(attr->len) + sizeof(struct stun_attr);
        if (x > len) {
            ret = -22;
            break;
        }
        ret |= stun_get_mapped(attr, arg);
        /* Clear attribute id: in case previous entry was a string,
         * this will act as the terminator for the string.
         */
        attr->attr = 0;
        data += x;
        len -= x;
    } // while
    /* Null terminate any string.
     * XXX NOTE, we write past the size of the buffer passed by the
     * caller, so this is potentially dangerous. The only thing that
     * saves us is that usually we read the incoming message in a
     * much larger buffer
     */
    *data = '\0';

    /* Now prepare to generate a reply, which at the moment is done
     * only for properly formed (len == 0) STUN_BINDREQ messages.
     */

    return ret;
}