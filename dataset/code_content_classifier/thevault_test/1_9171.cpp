void tw_define_lps(tw_lpid nlp, size_t msg_sz) {
    int  i;

    g_tw_nlp = nlp;

#ifdef ROSS_MEMORY
    g_tw_memory_sz = sizeof(tw_memory);
#endif

    g_tw_msg_sz = msg_sz;

    early_sanity_check();

    /*
     * Construct the KP array.
     */
    if( g_tw_nkp == 1 && g_tw_synchronization_protocol != OPTIMISTIC_DEBUG ) { // if it is the default, then check with the overide param
        g_tw_nkp = nkp_per_pe * g_tw_npe;
    }
    // else assume the application overloaded and has BRAINS to set its own g_tw_nkp

    g_tw_kp = (tw_kp **) tw_calloc(TW_LOC, "KPs", sizeof(*g_tw_kp), g_tw_nkp);

    /*
     * Construct the LP array.
     */
    g_tw_lp = (tw_lp **) tw_calloc(TW_LOC, "LPs", sizeof(*g_tw_lp), g_tw_nlp);

    switch(g_tw_mapping) {
        case LINEAR:
            map_linear();
            break;

        case ROUND_ROBIN:
            map_round_robin();
            break;

        case CUSTOM:
            if( g_tw_custom_initial_mapping ) {
                g_tw_custom_initial_mapping();
            } else {
                tw_error(TW_LOC, "CUSTOM mapping flag set but not custom mapping function! \n");
            }
            break;

        default:
            tw_error(TW_LOC, "Bad value for g_tw_mapping %d \n", g_tw_mapping);
    }

    theStateMap.resize(g_tw_nlp);
}