void DataSetBase::SortBySrcLengthAscending() {
	stable_sort(buf->items, buf->items + buf->count,
		[](void* a, void* b) {
			return ((Sample*)(a))->srcSeq->Size() <
				   ((Sample*)(b))->srcSeq->Size();
		});
}