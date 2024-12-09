void EWdetectorB::updateSWin(int rate) {
  struct SWinEntry *p, *new_entry;

  new_entry = new SWinEntry;
  new_entry->rate = rate;
  new_entry->weight = 1;
  new_entry->next = NULL;
  
  if (swin.tail)
    swin.tail->next = new_entry;
  swin.tail = new_entry;
  
  if (!swin.head)
    swin.head = new_entry;

  // Reset current rate.
  if (swin.count < EW_SWIN_SIZE) {
    swin.count++;
  } else {
    p = swin.head;
    swin.head = p->next;
    free(p);
  }
}