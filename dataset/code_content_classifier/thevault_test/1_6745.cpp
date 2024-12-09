int Address::str2addr(const char *str) const
{
	
	if (levels_ < 2) {
		int tmp = atoi(str);		
		if (tmp < 0)     
			return (tmp);
		u_int uitmp = (u_int) tmp;
		if (uitmp > ((unsigned long)(1 << bpl_[1])) ) {
			fprintf(stderr, "Error!!\nstr2addr:Address %u outside range of address field length %lu\n", 
				uitmp, ((unsigned long)(1<< bpl_[1])));
			exit(1);
		}
		return tmp;
	}
	/*
	  int istr[levels_], addr= 0;
	*/
	/*
	 * for VC++
	 */

	int *istr= new int[levels_];
	int addr= 0;
	
	RouteLogic::ns_strtok((char*)str, istr);
	for (int i = 0; i < levels_; i++) {
		assert (istr[i] - 1 >= 0);
		if (((unsigned long)--istr[i]) > ((unsigned long)(1 << bpl_[i+1])) ) {
			fprintf(stderr, "Error!!\nstr2addr:Address %d outside range of address field length %lu\n", 
				istr[i], ((unsigned long)(1<< bpl_[i+1])));
			exit(1);
		}
		addr = set_word_field(addr, istr[i],
				      NodeShift_[i+1], NodeMask_[i+1]);
	}
	
	delete [] istr;
	
	return addr;
}