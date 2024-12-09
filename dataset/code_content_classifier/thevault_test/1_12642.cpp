void core_exec_DPM_t::DL1_callback(void * const op)
{
  struct uop_t * uop = (struct uop_t*) op;
  class core_exec_DPM_t * E = (core_exec_DPM_t*)uop->core->exec;
  if(uop->alloc.LDQ_index != -1)
  {
#ifdef ZTRACE
    ztrace_print(uop,"e|load|returned from cache/memory");
#endif
    E->LDQ[uop->alloc.LDQ_index].first_byte_arrived = true;
    if((uop->exec.when_addr_translated <= E->core->sim_cycle) &&
        E->LDQ[uop->alloc.LDQ_index].last_byte_arrived &&
        !E->LDQ[uop->alloc.LDQ_index].hit_in_STQ) /* no match in STQ, so use cache value */
    {
      /* if load received value from STQ, it could have already
         committed by the time this gets called (esp. if we went to
         main memory) */
      uop->exec.when_data_loaded = E->core->sim_cycle;
      E->load_writeback(uop);
    }
  }
}