static void tw_sched_cancel_q(tw_pe * me) {
    tw_clock     start;
    tw_event    *cev;
    tw_event    *nev;

    start = tw_clock_read();
    while (me->cancel_q) {
        cev = me->cancel_q;
        me->cancel_q = NULL;

        for (; cev; cev = nev) {
            nev = cev->cancel_next;

            if (!cev->state.cancel_q) {
                tw_error(TW_LOC, "No cancel_q bit on event in cancel_q");
            }

            if(!cev->state.owner || cev->state.owner == TW_pe_free_q) {
                tw_error(TW_LOC, "Cancelled event, no owner!");
            }

            switch (cev->state.owner) {
                case TW_pe_event_q:
                    /* This event hasn't been added to our pq yet and we
                    * have not officially received it yet either.  We'll
                    * do the actual free of this event when we receive it
                    * as we spin out the event_q chain.
                    */
                    tw_eventq_delete_any(&me->event_q, cev);

                    tw_event_free(me, cev);
                    break;

                case TW_pe_anti_msg:
                    tw_event_free(me, cev);
                    break;

                case TW_pe_pq:
                    /* Event was not cancelled directly from the event_q
                    * because the cancel message came after we popped it
                    * out of that queue but before we could process it.
                    */
                    tw_pq_delete_any(me->pq, cev);
                    tw_event_free(me, cev);
                    break;

                case TW_kp_pevent_q:
                    /* The event was already processed.
                    * SECONDARY ROLLBACK
                    */
                    tw_kp_rollback_event(cev);
                    tw_event_free(me, cev);
                    break;

                default:
                    tw_error(TW_LOC, "Event in cancel_q, but owner %d not recognized", cev->state.owner);
            }
        }
    }

    me->stats.s_cancel_q += tw_clock_read() - start;
}