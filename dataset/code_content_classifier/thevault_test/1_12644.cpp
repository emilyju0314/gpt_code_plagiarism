bool core_exec_DPM_t::translated_callback(void * const op, const seq_t action_id)
{
  struct uop_t * uop = (struct uop_t*) op;
  struct core_exec_DPM_t * E = (core_exec_DPM_t*)uop->core->exec;
  if((uop->exec.action_id == action_id) && (uop->alloc.LDQ_index != -1))
    return uop->exec.when_addr_translated <= E->core->sim_cycle;
  else
    return true;
}