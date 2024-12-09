void
TimeList::getListString(char * buffer, int buffer_size) {
	int total_written, just_written;
	TimeElement * run;

	total_written = 1; // Need space for the /0 character
	for (run = head_; run; run = run->next_) {
		just_written = sprintf(buffer, 
					"%f ", run->time_);

		if (just_written == -1) {
			fprintf(stderr, "Ran out of buffer space when creating time list string\n");
			break;
		}
		//Advance buffer pointer past written characters
		buffer += just_written;
		total_written += just_written;
	}
}