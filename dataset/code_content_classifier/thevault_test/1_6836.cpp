void EWdetectorB::trace() {
  double db_rate = 0;
  double m_rate = 0;

  timeoutAList();
  m_rate = getMedianAList(0, alist.count);
  //printf("B ");
  db_rate = computeARR();

  if (!m_rate || !db_rate)
  {
	  ;//printAList();
  }

  printf("B %d %.2f %.2f %d %d %.2f %.2f\n", 
	 (int)now, cur_rate, avg_rate, arr_count, alarm, db_rate, m_rate);
}