int Fl_Check_Browser::remove(int item) {
  cb_item *p = find_item(item);
  
  // line at item exists
  if(p) {
    // tell the Browser_ what we will do
    deleting(p);

    // fix checked count
    if(p->checked)
      --nchecked_;
    
    // remove the node
    if (p->prev) 
      p->prev->next = p->next;
    else 
      first = p->next;
    if (p->next) 
      p->next->prev = p->prev;
    else 
      last = p->prev;
    
    free(p->text);
    free(p);
    
    --nitems_;
    cached_item = -1;
  }
  
  return (nitems_);
}