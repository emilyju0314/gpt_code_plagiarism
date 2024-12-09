void core_exec_DPM_t::RS_insert(struct uop_t * const uop)
{
  struct core_knobs_t * knobs = core->knobs;
  int RS_index;
  /* find a free RS entry */
  for(RS_index=0;RS_index < knobs->exec.RS_size;RS_index++)
  {
    if(RS[RS_index] == NULL)
      break;
  }
  if(RS_index == knobs->exec.RS_size)
    zesto_fatal("RS and RS_num out of sync",(void)0);

  RS[RS_index] = uop;
  RS_num++;
  RS_eff_num++;
  uop->alloc.RS_index = RS_index;

  #ifdef ZESTO_COUNTERS
  core->counters->RS.write++;
  #endif

  if(uop->decode.in_fusion)
    uop->exec.uops_in_RS ++; /* used to track when RS can be deallocated */
  uop->alloc.full_fusion_allocated = false;
}