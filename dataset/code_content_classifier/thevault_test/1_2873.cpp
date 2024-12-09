bool GCToOSInterface::VirtualCommit(void* address, size_t size, uint16_t node)
{
    if (node == NUMA_NODE_UNDEFINED)
    {
        return ::VirtualAlloc(address, size, MEM_COMMIT, PAGE_READWRITE) != nullptr;
    }
    else
    {
        assert(g_fEnableGCNumaAware);
        return ::VirtualAllocExNuma(::GetCurrentProcess(), address, size, MEM_COMMIT, PAGE_READWRITE, node) != nullptr;
    }
}