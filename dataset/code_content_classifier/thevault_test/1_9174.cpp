static void tw_sched_event_q(tw_pe * me) {
    tw_clock     start;
    tw_kp       *dest_kp;
    tw_event    *cev;
    tw_event    *nev;

    while (me->event_q.size) {
        cev = tw_eventq_pop_list(&me->event_q);

        for (; cev; cev = nev) {
            nev = cev->next;

            if(!cev->state.owner || cev->state.owner == TW_pe_free_q) {
                tw_error(TW_LOC, "no owner!");
            }
            if (cev->state.cancel_q) {
                cev->state.owner = TW_pe_anti_msg;
                cev->next = cev->prev = NULL;
                continue;
            }

            switch (cev->state.owner) {
                case TW_pe_event_q:
                    dest_kp = cev->dest_lp->kp;

                    if (dest_kp->last_time > cev->recv_ts) {
                        /* cev is a straggler message which has arrived
                        * after we processed events occuring after it.
                        * We need to jump back to before cev's timestamp.
                        */
                        start = tw_clock_read();
                        tw_kp_rollback_to(dest_kp, cev->recv_ts);
                        me->stats.s_rollback += tw_clock_read() - start;
                    }
                    start = tw_clock_read();
                    tw_pq_enqueue(me->pq, cev);
                    me->stats.s_pq += tw_clock_read() - start;
                    break;

                default:
                    tw_error(TW_LOC, "Event in event_q, but owner %d not recognized", cev->state.owner);
            }
        }
    }
}