int EWdetectorB::getMedianAList(int index, int count) {
  int m;
  
  if (!count)
    return 0;

  sortAList();
  //printAList();

  // Pick the entry with median avg_rate
  m = (int) (count / 2);
  if (2 * m == count) {
    return((getRateAList(index + m - 1) + getRateAList(index + m)) / 2);
  } else {
    return(getRateAList(index + m));
  }
}