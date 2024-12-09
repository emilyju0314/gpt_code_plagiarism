static uint32_t coap_calculate_packet_size(struct mg_coap_message *cm,
        size_t *len) {
    struct mg_coap_option *opt;
    uint32_t prev_opt_number;

    *len = 4; /* header */
    if (cm->msg_type > MG_COAP_MSG_MAX) {
        return MG_COAP_ERROR | MG_COAP_MSG_TYPE_FIELD;
    }
    if (cm->token.len > 8) {
        return MG_COAP_ERROR | MG_COAP_TOKEN_FIELD;
    }
    if (cm->code_class > 7) {
        return MG_COAP_ERROR | MG_COAP_CODE_CLASS_FIELD;
    }
    if (cm->code_detail > 31) {
        return MG_COAP_ERROR | MG_COAP_CODE_DETAIL_FIELD;
    }

    *len += cm->token.len;
    if (cm->payload.len != 0) {
        *len += cm->payload.len + 1; /* ... + 1; add payload marker */
    }

    opt = cm->options;
    prev_opt_number = 0;
    while (opt != NULL) {
        *len += 1; /* basic delta/length */
        *len += coap_get_ext_opt_size(opt->number);
        *len += coap_get_ext_opt_size((uint32_t) opt->value.len);
        /*
         * Current implementation performs check if
         * option_number > previous option_number and produces an error
         * TODO(alashkin): write design doc with limitations
         * May be resorting is more suitable solution.
         */
        if ((opt->next != NULL && opt->number > opt->next->number) ||
                opt->value.len > 0xFFFF + 269 ||
                opt->number - prev_opt_number > 0xFFFF + 269) {
            return MG_COAP_ERROR | MG_COAP_OPTIOMG_FIELD;
        }
        *len += opt->value.len;
        opt = opt->next;
    }

    return 0;
}