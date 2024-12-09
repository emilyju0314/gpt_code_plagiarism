void QA::DrainBuffers()
{
	int i, j, layers = 0;
	Scheduler& s = Scheduler::instance();
	double now = s.clock();
	// interval since last drain
	double interval = now - playTime_;
	playTime_ = now;  // update playTime

	if ((layers > 1) && (playing_[0] != 1)) {
		panic("ERROR in DrainBuffer: layers>0 but L0 isn't playing\n");
	}

	// Updating playout offset, but do nothing if we are in the initial
	// startup filling phase! This offset measures the playing progress
	// of the client side. It is actually the playing offset of the lowest
	// layer.

	// This is the real amount of data to be drained from layers
	int todrain[MAX_LAYER]; 
	// Expected offset of base layer after draining, without considering 
	// holes in data. This has to be satisfied, otherwise base layer will
	// be dropped and an error condition will be raised.
	poffset_ += (int)floor(interval*LAYERBW_+0.5);

	// Started from MAX_LAYER to make debugging easier
	for (i = MAX_LAYER-1; i >= 0; i--) {
		// If this layer is not being played, don't drain anything
		if (sending_[i] == 0) {
			todrain[i] = 0;
			drained_[i] = 0.0;
			continue; 
		}
		todrain[i] = outlist_[i].evict_head_offset(poffset_);
		assert(todrain[i] >= 0);
		buffer_[i] -= todrain[i];
		// A buffer must have more than one byte
		if ((int)buffer_[i] <= 0) {
			debug("Buffer %d ran dry: %.2f after draining, DROP\n",
			      i, buffer_[i]);
			playing_[i] = 0;
			sending_[i] = 0;
			buffer_[i] = 0;
	    
			/* Drop all higher layers if they still have data */
			for (j = i+1; j < MAX_LAYER; j++)
				if (sending_[j] == 1) {
/*
 					panic("# ERROR: layer %d \
is playing with %.2f buf but layer %d ran dry with %.2f buf\n",
 					      j, buffer_[j], i, buffer_[i]);
*/
 					debug("# DROP layer %d: it \
is playing with %.2f buf but layer %d ran dry with %.2f buf\n",
 					      j, buffer_[j], i, buffer_[i]);
					sending_[j] = 0;
					playing_[j] = 0;
					buffer_[j] = 0;
				}
			// We don't need to set it to -1. The old address 
			// will be used to see if we are sending old data if 
			// that later is added again
			//
			// XXX Where is this -1 mark ever used????
			// data_[i].set_start(-1); // drop layer i
		} else {
			// Prefetch for this layer. Round to whole segment
			int st = (int)floor((poffset_+pref_srtt_*LAYERBW_)
					    /seg_size_+0.5)*seg_size_;
			int et = (int)floor((poffset_+(pref_srtt_+interval)*
					   LAYERBW_)/seg_size_+0.5)*seg_size_;
			if (et > pref_[i]) {
				pref_[i] = et;
				MediaSegment s(st, et);
				check_availability(i, s);
			}
		}
	} /* end of for */
}