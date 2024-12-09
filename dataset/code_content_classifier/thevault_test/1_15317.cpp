void write(ofstream& outfile, bitset<tn>& F) {
	static int buflen = bufsize*8/tn;
	static const int charperbs = tn/8;
	for (int ci = 1; ci <= charperbs; ci++){
		char c = 0;
		for (int bi = 7; bi >= 0; bi--) {
			if (F.test(tn - ci*8 + bi)){
				c |= 0x1;
			}
			c <<= 1;
		}

		buffer[bufi*charperbs + ci - 1] = c;
	}
	bufi++;

	if (bufi == buflen) { // Flush buffer
		outfile.write(buffer, bufsize);
		bufi = 0;
	}
}