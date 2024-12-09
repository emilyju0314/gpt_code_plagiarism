int BayReassemblyQueue::add(Packet* pkt)
{
    hdr_tcp *tcph = hdr_tcp::access(pkt);
    hdr_cmn *th = hdr_cmn::access(pkt);

	int start = tcph->seqno();
	int end = start + th->size() - tcph->hlen();
	int tiflags = tcph->flags();
	seginfo *q, *p, *n;

	if (head_ == NULL) {
		// nobody there, just insert
		tail_ = head_ = new seginfo;
		head_->prev_ = NULL;
		head_->next_ = NULL;
		head_->startseq_ = start;
		head_->endseq_ = end;
		head_->flags_ = tiflags;
	} else {
		p = NULL;
		n = new seginfo;
		n->startseq_ = start;
		n->endseq_ = end;
		n->flags_ = tiflags;
		if (tail_->endseq_ <= start) {
			// common case of end of reass queue
			p = tail_;
			goto endfast;
		}

		q = head_;
		// look for the segment after this one
		while (q != NULL && (end > q->startseq_))
			q = q->next_;
		// set p to the segment before this one
		if (q == NULL)
			p = tail_;
		else
			p = q->prev_;

		if (p == NULL) {
			// insert at head
			n->next_ = head_;
			n->prev_ = NULL;
			head_->prev_ = n;
			head_ = n;
		} else {
endfast:
			// insert in the middle or end
			n->next_ = p->next_;
			if (p->next_)
				p->next_->prev_ = n;
			p->next_ = n;
			n->prev_ = p;
			if (p == tail_)
				tail_ = n;
		}
	}
	//
	// look for a sequence of in-order segments and
	// set rcv_nxt if we can
	//

	if (head_->startseq_ > rcv_nxt_)
		return 0;	// still awaiting a hole-fill

	tiflags = 0;
	p = head_;
	while (p != NULL) {
		// update rcv_nxt_ to highest in-seq thing
		// and delete the entry from the reass queue
		rcv_nxt_ = p->endseq_;
		tiflags |= p->flags_;
		q = p;
		if (q->prev_)
			q->prev_->next_ = q->next_;
		else
			head_ = q->next_;
		if (q->next_)
			q->next_->prev_ = q->prev_;
		else
			tail_ = q->prev_;
		if (q->next_ && (q->endseq_ < q->next_->startseq_)) {
			delete q;
			break;		// only the in-seq stuff
		}
		p = p->next_;
		delete q;
	}
	return (tiflags);
}