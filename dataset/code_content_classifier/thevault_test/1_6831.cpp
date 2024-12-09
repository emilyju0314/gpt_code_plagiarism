struct AListEntry * EWdetectorB::getMaxAList() {
  struct AListEntry *p, *pp, *max, *pm;

  //printAList();
  // find the max entry and remove
  p = pp = alist.head;
  max = pm = p;
  
  while (p) {
    if (p->avg_rate > max->avg_rate) {
      pm = pp;
      max = p;
    }
    
    pp = p;
    p = p->next;
  }
  
  // remove max from AList
  if (alist.head == max)
    alist.head = max->next;
  
  if (pm != max)
    pm->next = max->next;
  
  max->next = NULL;
  //printAList();

  return(max);
}