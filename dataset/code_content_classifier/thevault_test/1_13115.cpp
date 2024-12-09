void DataSetBase::SortByTgtLengthAscending()
{
	stable_sort(buf->items, buf->items + buf->count,
		[](void* a, void* b) {
			return ((Sample*)(a))->tgtSeq->Size() <
				   ((Sample*)(b))->tgtSeq->Size();
		});
}