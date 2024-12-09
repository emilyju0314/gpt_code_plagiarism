void core_exec_atom_t::store_dl1_split_callback(void * const op)
{
  struct uop_t * uop = (struct uop_t *)op;
  struct core_t * core = uop->core;
  struct core_exec_atom_t * E = (core_exec_atom_t*)core->exec;
  struct core_knobs_t * knobs = core->knobs;

#ifdef ZTRACE
  ztrace_print(uop,"c|store|written to cache/memory");
#endif

  zesto_assert((uop->alloc.STQ_index >= 0) && (uop->alloc.STQ_index < knobs->exec.STQ_size),(void)0);
  if(uop->exec.action_id == E->STQ[uop->alloc.STQ_index].action_id)
  {
    E->STQ[uop->alloc.STQ_index].last_byte_written = true;
    if(E->STQ[uop->alloc.STQ_index].first_byte_written)
      E->STQ[uop->alloc.STQ_index].write_complete = true;
  }
  core->return_uop_array(uop);
}