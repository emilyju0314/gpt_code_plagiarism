size_t CMBusCtrlr::tick() {
  int P = CONFIG->numProcs;

  if (currentJob->jobDone) {
    size_t arb = 0;


    bool found = false;
    for (int i=roundRobin; i<roundRobin + P; ++i) {
      arb = i % P;
      if (BUSRequests[arb]) {
        found = true;
        break;
      }
    }

    if (found) {
      roundRobin = (roundRobin + 1) % P;
      memset(BUSRequests, 0, sizeof(bool) * P);
      // the processors are responsible to set the BusCtrlr's currentJob
      // Because right now we don't have access to the pointer

      return arb;
    } else {
      // indicate that nothing is chosen in this round
      return P;
    }
  } else {
    currentJob->tick();
    // indicate that nothing is chosen in this round
    return P;
  }
}