static bool findEntryAndPrint(std::FILE *hashfile, long offset, std::size_t blocksReadSoFar, std::size_t blockCount) {
	std::cout << "Reading entry in offset " << offset << '\n';
	
	if (!std::fseek(hashfile, offset, SEEK_SET)) {
		EntryBlock e;
		
		if (std::fread(reinterpret_cast<char*>(&e), sizeof(e), 1, hashfile) && e.var.valid) {
			++blocksReadSoFar; // +1 because the entry block has been read
			
			foundEntryMessage(e.var, blocksReadSoFar, blockCount);
			return true;
		}
		else {
			std::cout << "Read failure. ";
		}
	}
	else {
		std::cout << "Seek failure (" << offset << "). ";
	}
	
	return false;
}