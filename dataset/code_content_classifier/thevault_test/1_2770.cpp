DbIterator(BufferManager<endian>& bufferManager, const DbSchema& schema, bool)
	: bufferManager_{bufferManager},
	  schema_{schema},
	  pageHandle_{},
	  currentEntryIndex_{0}
	{}