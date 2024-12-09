void 
RateLimitSessionList::mergeSessions(int myID) {
  RateLimitSession * session1 = first_;
  while (session1 != NULL) {
    AggSpec * agg1 = session1->aggSpec_;
    RateLimitSession * session2 = session1->next_;
    while (session2 != NULL) {
      AggSpec * agg2 = session2->aggSpec_;
      if (session1->origin_== myID && session2->origin_ == myID &&
	  agg1->dstON_  && agg2->dstON_) {
	int bits = AggSpec::prefixBitsForMerger(agg1, agg2);
	if (bits==0) {
		
	    //a measure of how much are we broadening.
	    int bitsDiff = ((agg1->dstBits_<agg2->dstBits_)? agg1->dstBits_: agg2->dstBits_) - bits;
	    int prefix = PrefixTree::getPrefixBits(agg1->dstPrefix_, bits);
	    int count = getMySubsetCount(prefix, bits, myID);
	    if (count <2) {
		    printf("Error: Anomaly \n");
		    exit(-1);
	    }
	    if (PushbackAgent::mergerAccept(count, bits, bitsDiff)) {
		    merge(prefix, bits, myID);
	    }
	}
      }
      session2 = session2->next_;
    }
    session1 = session1->next_;
  }
}