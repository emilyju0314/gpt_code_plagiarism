int EWdetectorB::computeARR() {
  int i, agg_rate;

  // Explicit garbage collection first 
  //  before both choosing HBFs and searching AList
  //printf("before timeout ");
  timeoutAList();
  //printf("after timeout ");

  // do nothing if no entry exists
  if (!alist.count) 
    return 0;

  // Pick the 10% highest bandwidth flows
  arr_count = (int) (alist.count * 0.1 + 1);

  // Sort AList first
  sortAList();

  // Calculate the ARR for HBFs
  // Use mean
  agg_rate = 0;
  for (i = 0; i < arr_count; i++) {
    agg_rate += getRateAList(i);
  }
  
  if (i)
    agg_rate = (int) (agg_rate / i);
  else {
    printf("No MAX returned from ALIST!!!\n");
  }
  
  // Use median (the median for the list or median for HBFs?)
  //agg_rate = getMedianAList(0, k);
  //printf("%f %d %d %d\n", now, k, agg_rate, getMedianAList(0, k));
  
  return(agg_rate);
}