void Line::flood(int start, int seqno)
{
	SRM_Event *se = new SRM_Event(seqno, SRM_DATA, start);
	node_[start].send(se);
}