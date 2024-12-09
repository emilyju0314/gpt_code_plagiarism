PinoPacket::PinoPacket(string pkt)
{
        /* TODO */   // unsigned char   pkt_type; unsigned short pkt_len; string pkt_stream;
        char* pPkt = convertStreamToPacket(pkt);
        // skip first byte  version
        pPkt++;
        // get packet type
        pkt_type = *pPkt;
        pPkt++;
        // get packet length
        pkt_len = *((unsigned short *) packet);
        pPkt += 2; // skip the length
        // get body length
        unsigned short body_len = *((unsigned short *) pPkt);
        pPkt += 2; // skip the length
        // get body string
        string pkt_body(pPkt);   // cstr to string

        buildPacket(pkt_type, pkt_body, body_len);
}