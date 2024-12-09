void EWdetectorP::trace() {
  printf("P %d %.2f %.2f %d %d %d %d %d %d %d\n", 
	 (int)now, cur_rate, avg_rate, alarm,
	 cur_p.arrival - last_p_db.arrival,
	 cur_p.dept - last_p_db.dept,
	 cur_p.drop - last_p_db.drop,  
	 cur_p.arrival, cur_p.dept, cur_p.drop);

  last_p_db.arrival = cur_p.arrival;
  last_p_db.dept = cur_p.dept;
  last_p_db.drop = cur_p.drop;
}