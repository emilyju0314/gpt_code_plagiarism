static void foundEntryMessage(const Entry& e, std::size_t blocksRead, std::size_t blockCount) {
	std::cout << "Entry found:\n\n";
	printEntry(e);
	std::cout << blocksRead << " block" << (blocksRead > 1? "s were" : " was") << " read.\n";
	std::cout << "The file currently has " << blockCount << " total blocks." << std::endl;
}