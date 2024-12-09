void EWdetectorB::ravgSWin() {
  struct SWinEntry *p;
  float sum = 0;
  float t_weight = 0;

  //printf("Calculate running average over the sliding window:\n");
  p = swin.head;
  //printf("after p\n");

  while (p) {
    //printSWinEntry(p, i++);
    sum += p->rate * p->weight;
    t_weight += p->weight;
    p = p->next;
  }
  p = NULL;
  //printf("\n");  

  swin.ravg = (int)(sum / t_weight);

  //  printf("Ravg: %d\n", swin.ravg);
}