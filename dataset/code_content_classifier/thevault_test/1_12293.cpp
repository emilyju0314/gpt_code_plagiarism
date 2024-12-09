void LegacyAllocator::DeAllocate(pointer_type ptr, [[maybe_unused]] const char* file, [[maybe_unused]] const int line, size_type byteSize, size_type alignment)
    {
        AZ_PROFILE_MEMORY_FREE_EX(MemoryReserved, file, line, ptr);
        AZ_MEMORY_PROFILE(ProfileDeallocation(ptr, byteSize, alignment, nullptr));
        m_schema->DeAllocate(ptr, byteSize, alignment);
    }