void CMemoryManager::StartUp()
{

	std::cout << "ALLOCATION: Allocating " << MEMORY_ALLOCATION_SIZE_MB * MB_TO_GB_SCALE << " GB onto heap" << std::endl;
	

	auto t1 = EROS_TIME_NOW;

	// Allocate static-sized memory block on heap (requires user->kernal->user context switch)
	m_baseAddress = (unsigned char*) malloc(MEMORY_ALLOCATION_SIZE_MB * MB_TO_B_SCALE);
	
	// Assert memory was correctly initialized
	EROS_TRAP(m_baseAddress != nullptr);
	m_curAddress = m_baseAddress;

	auto t2 = EROS_TIME_NOW;
	auto duration = EROS_DURATION_MILLI(t1, t2);
	
	std::cout << "Heap allocation time: " << duration << " milliseconds" << std::endl;

	CreateAllocators();
}