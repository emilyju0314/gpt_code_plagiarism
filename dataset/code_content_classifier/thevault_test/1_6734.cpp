void
DSDV_Agent::output_rte(const char *prefix, rtable_ent * prte, DSDV_Agent * a)
{
  a->trace("DFU: deimplemented");
  printf("DFU: deimplemented");

  prte = 0;
  prefix = 0;
#if 0
  printf ("%s%d %d %d %d %f %f %f %f 0x%08x\n",
	  prefix, prte->dst, prte->hop, prte->metric, prte->seqnum,
	  prte->udtime, prte->new_seqnum_at, prte->wst, prte->changed_at,
	  (unsigned int) prte->timeout_event);
  a->trace ("VTE %.5f %d %d %d %d %f %f %f %f 0x%08x",
          Scheduler::instance ().clock (), prte->dst, prte->hop, prte->metric,
	  prte->seqnum, prte->udtime, prte->new_seqnum_at, prte->wst, prte->changed_at,
	    prte->timeout_event);
#endif
}