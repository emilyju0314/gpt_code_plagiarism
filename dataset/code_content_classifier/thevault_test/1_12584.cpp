void
core_decode_DPM_t::recover_uopQ(const struct Mop_t * const Mop)
{
  struct core_knobs_t * knobs = core->knobs;

  while(uopQ_num)
  {
    int index = moddec(uopQ_tail,knobs->decode.uopQ_size); //(uopQ_tail-1+knobs->decode.uopQ_size) % knobs->decode.uopQ_size;
    if(uopQ[index]->Mop == Mop)
      return;
    if(uopQ[index]->decode.is_fusion_head)
      uopQ_eff_num -= uopQ[index]->decode.fusion_size;
    else
      uopQ_eff_num --;
    uopQ_num--;
    uopQ[index] = NULL;
    uopQ_tail = index;

    #ifdef ZESTO_COUNTERS
    core->counters->uopQ.write++;
    #endif
  }
  uopQ_eff_num = 0;
}