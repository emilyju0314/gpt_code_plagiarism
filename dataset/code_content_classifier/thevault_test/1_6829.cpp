int EWdetectorB::getRateAList(int index) {
  struct AListEntry *p;

  //printf("%d\n", index);
  p = alist.head;
  for (int i = 0; i < index; i++) {
    if (p)
      p = p->next;
  }
  
  if (p)
    return ((int)p->avg_rate);

  printf("Error in AList!\n");
  return(0);
}