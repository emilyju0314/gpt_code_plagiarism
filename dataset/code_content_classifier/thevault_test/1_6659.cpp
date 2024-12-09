bool
OLSR::seq_num_bigger_than(u_int16_t s1, u_int16_t s2) {
	return (s1 > s2 && s1-s2 <= OLSR_MAX_SEQ_NUM/2)
		|| (s2 > s1 && s2-s1 > OLSR_MAX_SEQ_NUM/2);
}