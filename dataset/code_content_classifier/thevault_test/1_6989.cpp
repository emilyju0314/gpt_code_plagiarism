AppData* QA::output(int& size, int layer)
{
	int i;
	assert((sending_[layer] == 1) || (startTime_ == -1));

	// In order to send out a segment, all corresponding segments of 
	// the lower layers must have been sent out
	if (layer > 0)
		if (data_[layer-1].start() <= data_[layer].start())
			return output(size, layer-1);

	// Get and output the data at the current data pointer
	MediaRequest q(MEDIAREQ_GETSEG);
	q.set_name(page_);
	q.set_layer(layer);
	q.set_st(data_[layer].start());
	q.set_datasize(seg_size_);
	q.set_app(this);
	AppData* res = target()->get_data(size, &q);

	assert(res != NULL);
	HttpMediaData *p = (HttpMediaData *)res; 

	if (p->datasize() <= 0) {
		// When the data is not available:
		// Should NOT advance sending data pointer because 
		// if this is a cache which is downloading from a slow
		// link, it is possible that the requested data will
		// become available in the near future!!

		// We have already sent out the last segment of the base layer,
		// now we are requested for the segment beyond the last one
		// in the base layer. In this case, consider the transmission
		// is complete and tear down the connection.
		if (p->is_finished()) {
			rap()->stop();
			// XXX Shouldn't this be done inside mcache/mserver??
			Tcl::instance().evalf("%s finish-stream %s", 
					      target()->name(), name());
		} else if (!p->is_last()) {
			// If we coulnd't find anything within q, move data 
			// pointer forward to skip holes.
			MediaSegment tmp(q.et(), q.et()+seg_size_);
			check_layers(p->layer(), tmp);
			// If we can, advance. Otherwise wait for
			// lower layers to advance first.
			if (tmp.datasize() > 0) {
				assert(tmp.datasize() <= seg_size_);
				data_[p->layer()].set_start(tmp.start());
				data_[p->layer()].set_end(tmp.end());
			}
		}
		delete p;
		return NULL;
	}

	// Set current data pointer to the right ones
	// If available data is more than seg_size_, only 
	// advance data pointer by seg_size_. If less data 
	// is available, only advance data by the amount 
	// of available data.
	//
	// XXX Currently the cache above does NOT pack data 
	// from discontinugous blocks into one packet. May 
	// need to do that later. 
// 		if (p->is_last())
// 			data_[p->layer()].set_last();
	assert((p->datasize() > 0) && (p->datasize() <= seg_size_));
	// XXX Before we move data pointer forward, make sure we don't violate
	// layer ordering rules. Note we only need to check end_ because 
	// start_ is p->et() which is guaranteed to be valid
	MediaSegment tmp(p->et(), p->et()+seg_size_);
	check_layers(p->layer(), tmp);
	if (tmp.datasize() > 0) {
		assert(tmp.datasize() <= seg_size_);
		data_[p->layer()].set_start(tmp.start());
		data_[p->layer()].set_end(tmp.end());
	} else {
		// Print error messages, do not send anything and wait for 
		// next time so that hopefully lower layers will already 
		// have advanced.
		fprintf(stderr, "# ERROR We cannot advance pointers for "
			"segment (%d %d)\n", tmp.start(), tmp.end());
		for (i = 0; i < layer; i++) 
			fprintf(stderr, "Layer %d, data ptr (%d %d) \n",
				i, data_[i].start(), data_[i].end());
		delete p;
		return NULL;
	}

	// Let me know that we've sent out this segment. This is used
	// later to drain data (DrainBuffers())
	outlist_[p->layer()].add(MediaSegment(p->st(), p->et()));

	buffer_[layer] += p->datasize();
	bw_[layer] += p->datasize();
	drained_[layer] -= p->datasize();
  
	//offset_[layer] += seg_size_;
	avgrate_ = rate_weight_*rate() + (1-rate_weight_)*avgrate_;

	// DEBUG check
	for (i = 0; i < layer-1; i++)
		if (data_[i].end() < data_[i+1].end()) {
			for (int j = 0; j < layer; j++)
				fprintf(stderr, "layer i: (%d %d)\n", 
					data_[i].start(), data_[i].end());
			panic("# ERROR Wrong layer sending order!!\n");
		}

	return res;
}