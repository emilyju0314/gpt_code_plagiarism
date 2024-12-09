void ARMInterceptRouting::BuildPreCallRouting() {
  // create closure trampoline jump to prologue_routing_dispath with the `entry_` data
  ClosureTrampolineEntry *cte = ClosureTrampoline::CreateClosureTrampoline(entry_, (void *)prologue_routing_dispatch);
  entry_->prologue_dispatch_bridge = cte->address;

  // build the fast forward trampoline jump to the normal routing(prologue_routing_dispatch).
  if (branch_type_ == ARM_B_Branch || branch_type_ == Thumb1_B_Branch || branch_type_ == Thumb2_B_Branch) {
    DLOG("%s", "[*] Fast forward to Pre-ClosureTrampoline\n");
    BuildFastForwardTrampoline();
  }

  DLOG("[*] create pre call closure trampoline to 'prologue_routing_dispatch' at %p\n", cte->address);
}