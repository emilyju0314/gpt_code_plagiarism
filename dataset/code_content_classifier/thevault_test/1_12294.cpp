LegacyAllocator::pointer_type LegacyAllocator::ReAllocate(pointer_type ptr, size_type newSize, size_type newAlignment, [[maybe_unused]] const char* file, [[maybe_unused]] const int line)
    {
        if (newAlignment == 0)
        {
            // Some STL containers, like std::vector, seem to have a requirement where a specific minimum alignment will be chosen when the alignment is set to 0
            // Take a look at _Allocate_manually_vector_aligned in xmemory0
            newAlignment = sizeof(void*) * 2;
        }

        AZ_MEMORY_PROFILE(ProfileReallocationBegin(ptr, newSize));
        AZ_PROFILE_MEMORY_FREE_EX(MemoryReserved, file, line, ptr);
        pointer_type newPtr = m_schema->ReAllocate(ptr, newSize, newAlignment);
        AZ_PROFILE_MEMORY_ALLOC_EX(MemoryReserved, file, line, newPtr, newSize, "LegacyAllocator Realloc");
        AZ_MEMORY_PROFILE(ProfileReallocationEnd(ptr, newPtr, newSize, newAlignment));
        AZ_Assert(newPtr || newSize == 0, "OOM - Failed to reallocate %zu bytes from LegacyAllocator", newSize);
        return newPtr;
    }