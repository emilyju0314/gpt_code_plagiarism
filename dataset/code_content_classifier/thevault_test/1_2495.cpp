bool check_global_equiv(unsigned long long local_value) {

  const int node = rtt_c4::node();
  const int nodes = rtt_c4::nodes();

  bool pass = false;

  // return true if serial, if not then do check on all processors
  if (nodes == 1)
    pass = true;
  else {
    // value from processor above local processor
    unsigned long long neighbors_value = local_value - 1;

    if (node > 0 && node < nodes - 1) {
      rtt_c4::send(&local_value, 1, node - 1, 600);
      rtt_c4::receive(&neighbors_value, 1, node + 1, 600);
      if (local_value == neighbors_value)
        pass = true;
    } else if (node == nodes - 1) {
      rtt_c4::send(&local_value, 1, node - 1, 600);
      pass = true;
    } else if (node == 0) {
      rtt_c4::receive(&neighbors_value, 1, node + 1, 600);
      if (local_value == neighbors_value)
        pass = true;
    } else {
      Insist(0, "Something is wrong with nodes!");
    }
  }

  // sync everything so we don't leave before all processors are finished
  rtt_c4::global_barrier();

  // return result
  return pass;
}