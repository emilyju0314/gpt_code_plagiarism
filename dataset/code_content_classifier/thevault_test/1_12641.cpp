bool core_exec_DPM_t::check_load_issue_conditions(const struct uop_t * const uop)
{
  struct core_knobs_t * knobs = core->knobs;
  /* are all previous STA's known? If there's a match, is the STD ready? */
  bool sta_unknown = false;
  bool regular_match = false;
  bool partial_match = false;
  bool oracle_regular_match = false;
  bool oracle_partial_match = false;
  int i;
  int match_index = -1;
  int oracle_index = -1;
  int num_stores = 0; /* need this extra condition because STQ could be full with all stores older than the load we're considering */

  /* don't reissue someone who's already issued */
  zesto_assert((uop->alloc.LDQ_index >= 0) && (uop->alloc.LDQ_index < knobs->exec.LDQ_size),false);
  if(LDQ[uop->alloc.LDQ_index].when_issued != TICK_T_MAX)
    return false;

  md_addr_t ld_addr1 = LDQ[uop->alloc.LDQ_index].uop->oracle.virt_addr;
  md_addr_t ld_addr2 = LDQ[uop->alloc.LDQ_index].virt_addr + uop->decode.mem_size - 1;

  /* this searches the senior STQ as well. */
  for(i=LDQ[uop->alloc.LDQ_index].store_color;
      ((modinc(i,knobs->exec.STQ_size)) != STQ_senior_head) && (STQ[i].uop_seq < uop->decode.uop_seq) && (num_stores < STQ_senior_num);
      i=moddec(i,knobs->exec.STQ_size) )
  {
    /* check addr match */
    int st_mem_size = STQ[i].mem_size;
    int ld_mem_size = uop->decode.mem_size;
    md_addr_t st_addr1, st_addr2;
    
    if(STQ[i].addr_valid)
      st_addr1 = STQ[i].virt_addr; /* addr of first byte */
    else
    {
      zesto_assert(STQ[i].sta,false);
      st_addr1 = STQ[i].sta->oracle.virt_addr; /* addr of first byte */
      sta_unknown = true;
    }
    st_addr2 = st_addr1 + st_mem_size - 1; /* addr of last byte */

    zesto_assert(st_mem_size,false);
    zesto_assert(ld_mem_size,false);
    /* XXX: The following assert should be used, but under RHEL5-compiled binaries,
       there seems to be some weird thing going on where the GS segment register is
       getting zeroed out somewhere which later leads to a null-pointer dereference.
       On some test programs, this didn't seem to cause any problems, so for now
       we're just leaving it this way. */
    zesto_assert((st_addr1 && st_addr2) || (STQ[i].sta && STQ[i].sta->Mop->oracle.spec_mode),false);

    if((st_addr1 <= ld_addr1) && (st_addr2 >= ld_addr2)) /* store write fully overlaps the load address range */
    {
      if((match_index == -1) && (STQ[i].addr_valid))
      {
        match_index = i;
        regular_match = true;
      }

      if(oracle_index == -1)
      {
        oracle_index = i;
        oracle_regular_match = true;
      }
    }
    else if((st_addr2 < ld_addr1) || (st_addr1 > ld_addr2)) /* store addr is completely before or after the load */
    {
      /* no conflict here */
    }
    else /* partial store */
    {
      if((match_index == -1) && (STQ[i].addr_valid))
      {
        match_index = i;
        partial_match = true;
      }

      if(oracle_index == -1)
      {
        oracle_index = i;
        oracle_partial_match = true;
      }
    }
    num_stores++;
  }

  if(partial_match)
  {
    /* in presence of (known) partial store forwarding, stall until store *commits* */
    LDQ[uop->alloc.LDQ_index].partial_forward = true;
    return false;
  }

  return memdep->lookup(uop->Mop->fetch.PC,sta_unknown,oracle_regular_match,oracle_partial_match);
}