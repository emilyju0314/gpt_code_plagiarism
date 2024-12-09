void core_exec_atom_t::RS_insert(struct uop_t * const uop)
{
  struct core_knobs_t * knobs = core->knobs;
 
  zesto_assert(RS[uop->alloc.port_assignment] == NULL ,(void)0);
  RS[uop->alloc.port_assignment] = uop;
  RS_num++;
  RS_eff_num++;
  uop->alloc.RS_index = uop->alloc.port_assignment;

  #ifdef ZESTO_COUNTERS
  core->counters->RS.write++;
  #endif

  if(uop->decode.in_fusion)
    uop->exec.uops_in_RS ++; /* used to track when RS can be deallocated */
  uop->alloc.full_fusion_allocated = false;
}