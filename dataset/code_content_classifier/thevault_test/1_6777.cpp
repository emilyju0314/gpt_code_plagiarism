int 
LoggingDataStruct::consolidateStatus() {

  double rate = 0;
  int all = 1;
  LoggingDataStructNode * node = first_;
  while (node != NULL) {
    if (!node->gotStatus_) {
      if (node->statusArrivalRate_<0) {
	//condition 1 above.
	printf("LGDS: Error: This should never happen now\n");
	exit(-1);
	//return -1;
      }
      else {
	all = 0;
      }
    }
    rate += node->statusArrivalRate_;
    node = node->next_;
  }

  gotStatusAll_ = all;
  statusArrivalRateAll_=rate;

  return all;
}