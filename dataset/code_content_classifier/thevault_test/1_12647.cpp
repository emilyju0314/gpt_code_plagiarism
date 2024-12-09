void core_exec_DPM_t::RS_fuse_insert(struct uop_t * const uop)
{
  /* fusion body shares same RS entry as fusion head */
  uop->alloc.RS_index = uop->decode.fusion_head->alloc.RS_index;
  RS_eff_num++;
  uop->decode.fusion_head->exec.uops_in_RS ++;
  if(uop->decode.fusion_next == NULL)
    uop->decode.fusion_head->alloc.full_fusion_allocated = true;

  #ifdef ZESTO_COUNTERS
  core->counters->RS.write++;
  #endif
}