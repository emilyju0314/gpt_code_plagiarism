int queue_peek(Queue *const q, int64_t idx, struct QueueData *const d) {
	struct FileItr itr;
	memset(&itr, 0, sizeof(itr));
	struct JournalEntry  je;
	int results = queue_index_lookup(q,  idx, &itr,d, &je);
	closeFileItr(&itr);
	return results;
}