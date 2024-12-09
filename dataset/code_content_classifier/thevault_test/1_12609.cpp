void
core_alloc_DPM_t::recover(void)
{
  struct core_knobs_t * knobs = core->knobs;
  int stage,i;
  for(stage=0;stage<knobs->alloc.depth;stage++)
  {
    /* slot N-1 is most speculative, start from there */
    if(occupancy[stage])
      for(i=knobs->alloc.width-1;i>=0;i--)
      {
        if(pipe[stage][i])
        {
          pipe[stage][i] = NULL;
          occupancy[stage]--;
          zesto_assert(occupancy[stage] >= 0,(void)0);
        }
      }
    zesto_assert(occupancy[stage] == 0,(void)0);
  }
}