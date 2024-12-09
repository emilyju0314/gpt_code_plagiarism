EWdetectorB::EWdetectorB() : EWdetector() {
  drop_p = 0;
  arr_count = 0;

  adjustor = 1.0;

  // Initialize ALIST
  alist.head = alist.tail = NULL;
  alist.count = 0;

  swin.head = swin.tail = NULL;
  swin.count = swin.ravg = 0;
}