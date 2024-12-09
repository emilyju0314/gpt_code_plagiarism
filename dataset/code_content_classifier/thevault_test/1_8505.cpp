static char *coap_get_token(char *ptr, struct mbuf *io,
                            struct mg_coap_message *cm) {
    if (cm->token.len != 0) {
        if (ptr + cm->token.len > io->buf + io->len) {
            cm->flags |= MG_COAP_NOT_ENOUGH_DATA;
            return NULL;
        } else {
            cm->token.p = ptr;
            ptr += cm->token.len;
            cm->flags |= MG_COAP_TOKEN_FIELD;
        }
    }

    return ptr;
}