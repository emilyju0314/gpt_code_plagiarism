int EqualSeqno(void *i1, void *i2)
{ 
	return (((TransHistoryEntry *) i1)->seqno == 
		((TransHistoryEntry *) i2)->seqno);
}