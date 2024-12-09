void
core_commit_atom_t::recover(const struct Mop_t * const Mop)
{
  assert(Mop != NULL);
  struct core_knobs_t * knobs = core->knobs;
  /**/ 
  core->exec->last_Mop_seq = core->global_seq + 1;

  if(ROB_num > 0)
  {
    /* requested uop should always be in the ROB */
    int index = moddec(ROB_tail,knobs->commit.ROB_size); //(ROB_tail-1+knobs->commit.ROB_size) % knobs->commit.ROB_size;

    /* if there's only the one inst in the pipe, then we don't need to drain */
    if(knobs->alloc.drain_flush && (ROB[index]->Mop != Mop))
      core->alloc->start_drain();

    while(ROB[index] && (ROB[index]->Mop != Mop))
    {
      int i;
      struct uop_t * dead_uop = ROB[index];

      zesto_assert(ROB_num > 0,(void)0);

      if(dead_uop->decode.in_fusion)
      {
        zesto_assert(dead_uop->decode.is_fusion_head,(void)0);
        while(dead_uop->decode.fusion_next)
          dead_uop = dead_uop->decode.fusion_next;
        zesto_assert(dead_uop != dead_uop->decode.fusion_head,(void)0);
      }

      while(dead_uop)
      {
        /* squash this instruction - this invalidates all in-flight actions (e.g., uop execution, cache accesses) */
        dead_uop->exec.action_id = core->new_action_id();
        if(dead_uop->timing.when_allocated != TICK_T_MAX)
          ROB_eff_num--;

        if(dead_uop->alloc.RS_index != -1) /* currently in RS */
          core->exec->RS_deallocate(dead_uop);

        /* In the following, we have to check it the uop has even been allocated yet... this has
           to do with our non-atomic implementation of allocation for fused-uops */
        if(dead_uop->decode.is_std) /* dealloc when we get to the STA */
        {
          if(dead_uop->timing.when_allocated != TICK_T_MAX)
            core->exec->STQ_squash_std(dead_uop);
        }
        else if(dead_uop->decode.is_sta)
        {
          if(dead_uop->timing.when_allocated != TICK_T_MAX)
            core->exec->STQ_squash_sta(dead_uop);
        }

        /* clean up idep/odep pointers.  Since we're working our
           way back from the most speculative instruction, we only
           need to clean-up our parent's forward-pointers (odeps)
           and our own back-pointers (our fwd-ptrs would have
           already cleaned-up our own children). */
        for(i=0;i<MAX_IDEPS;i++)
        {
          struct uop_t * parent = dead_uop->exec.idep_uop[i];
          if(parent) /* I have an active parent */
          {
            struct odep_t * prev, * current;
            prev = NULL;
            current = parent->exec.odep_uop;
            while(current)
            {
              if((current->uop == dead_uop) && (current->op_num == i))
                break;
              prev = current;
              current = current->next;
            }

            zesto_assert(current,(void)0);

            /* remove self from parent's odep list */
            if(prev)
              prev->next = current->next;
            else
              parent->exec.odep_uop = current->next;

            /* eliminate my own idep */
            dead_uop->exec.idep_uop[i] = NULL;

            /* return the odep struct */
            core->return_odep_link(current);
          }
        }

        zesto_assert(dead_uop->exec.odep_uop == NULL,(void)0);

        if((!dead_uop->decode.in_fusion) || dead_uop->decode.is_fusion_head)
          dead_uop = NULL;
        else
        {
          /* this is ugly... need to traverse fused uop linked-list
             in reverse; most fused uops are short, so we're just
             going to re-traverse... if longer fused uops are
             supported, it may make sense to implement a
             doubly-linked list instead. */
          struct uop_t * p = ROB[index];
          while(p->decode.fusion_next != dead_uop)
            p = p->decode.fusion_next;

          dead_uop = p;
        }
      }

      #ifdef ZESTO_COUNTERS
      core->counters->ROB.write_tag++;
      #endif

      ROB[index] = NULL;
      ROB_tail = moddec(ROB_tail,knobs->commit.ROB_size); //(ROB_tail-1+knobs->commit.ROB_size) % knobs->commit.ROB_size;
      ROB_num --;
      zesto_assert(ROB_num >= 0,(void)0);
      zesto_assert(ROB_eff_num >= 0,(void)0);

      index = moddec(index,knobs->commit.ROB_size); //(index-1+knobs->commit.ROB_size) % knobs->commit.ROB_size;
    }
  }
}