void core_exec_DPM_t::load_miss_reschedule(void * const op, const int new_pred_latency)
{
  struct uop_t * uop = (struct uop_t*) op;
  struct core_t * core = uop->core;
  struct core_exec_DPM_t * E = (core_exec_DPM_t*)core->exec;
  struct core_knobs_t * knobs = core->knobs;
  zesto_assert(uop->decode.is_load,(void)0);
  zesto_assert((uop->alloc.LDQ_index >= 0) && (uop->alloc.LDQ_index < knobs->exec.LDQ_size),(void)0);

  /* if we've speculatively woken up our dependents, we need to
     snatch them back out of the execution pipeline and replay them
     later (but if the load already hit in the STQ, then don't need
     to replay) */
  if(E->LDQ[uop->alloc.LDQ_index].speculative_broadcast && !E->LDQ[uop->alloc.LDQ_index].hit_in_STQ)
  {
#ifdef ZTRACE
    ztrace_print(uop,"e|cache-miss|no STQ hit");
#endif
    /* we speculatively scheduled children assuming we'd hit in the
       previous cache level, but we didn't... so put children back
       to sleep */
    uop->timing.when_otag_ready = TICK_T_MAX;
    struct odep_t * odep = uop->exec.odep_uop;
    while(odep)
    {
      odep->uop->timing.when_itag_ready[odep->op_num] = TICK_T_MAX;
      E->snatch_back(odep->uop);

      odep = odep->next;
    }

    /* now assume a hit in this cache level */
    odep = uop->exec.odep_uop;
    if(new_pred_latency != BIG_LATENCY)
      uop->timing.when_otag_ready = core->sim_cycle + new_pred_latency - knobs->exec.payload_depth - 1;

    while(odep)
    {
      odep->uop->timing.when_itag_ready[odep->op_num] = uop->timing.when_otag_ready;

      /* put back on to readyQ if appropriate */
      int j;
      tick_t when_ready = 0;
      zesto_assert(!odep->uop->exec.in_readyQ,(void)0);

      for(j=0;j<MAX_IDEPS;j++)
        if(when_ready < odep->uop->timing.when_itag_ready[j])
          when_ready = odep->uop->timing.when_itag_ready[j];

      odep->uop->timing.when_ready = when_ready;
      if(when_ready < TICK_T_MAX)
      {
        E->insert_ready_uop(odep->uop);
      }

      odep = odep->next;
    }
  }
#ifdef ZTRACE
  else
    ztrace_print(uop,"e|cache-miss|STQ hit so miss not observed");
#endif

}