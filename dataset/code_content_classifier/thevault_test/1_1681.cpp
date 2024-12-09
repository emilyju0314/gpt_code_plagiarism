uint8_t *bns_get_seq_v2(int64_t l_pac, const uint8_t *pac, int64_t beg, int64_t end, int64_t *len, uint8_t *seqb)
{
	uint8_t *seq = 0;
	if (end < beg) end ^= beg, beg ^= end, end ^= beg; // if end is smaller, swap
	if (end > l_pac<<1) end = l_pac<<1;
	if (beg < 0) beg = 0;
	if (beg >= l_pac || end <= l_pac) {
		int64_t k, l = 0;
		*len = end - beg;
		assert(end-beg < BATCH_SIZE * SEEDS_PER_READ * sizeof(SeqPair));
		
		//seq = (uint8_t*) malloc(end - beg);
		// seq = seqb;
		if (beg >= l_pac) { // reverse strand
#if 0   // orig			
			int64_t beg_f = (l_pac<<1) - 1 - end;
			int64_t end_f = (l_pac<<1) - 1 - beg;
			for (k = end_f; k > beg_f; --k) {
				seq[l++] = 3 - _get_pac(pac, k);
				assert(seq[l-1] == ref_string[beg + l - 1]);
			}
#else
			seq = ref_string + beg;
#endif
		} else { // forward strand
#if 0
			for (k = beg; k < end; ++k) {
				seq[l++] = _get_pac(pac, k);
				assert(seq[l-1] == ref_string[k]);
			}
#else
			seq = ref_string + beg;
#endif			
		}

	} else *len = 0; // if bridging the forward-reverse boundary, return nothing
	return seq;
}