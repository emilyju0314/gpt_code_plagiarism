NvDlaError Pool::deallocate(TensorBufferDesc* bufferDesc, NvU16 batchId)
{
    NvDlaError e = NvDlaSuccess;
    NvU64 buffAddr = 0;
    if ( !bufferDesc->allocated(batchId) )
    {
        ORIGINATE_ERROR_FAIL(NvDlaError_InvalidState, "Attempt to deallocate an un-allocated buffer");
    }
    buffAddr = reinterpret_cast<NvU64>(m_base_addr) + bufferDesc->poolOffset(batchId);

    if ( debug() )
    {
        gLogInfo << "\t\t" << name() << " dealloc " << bufferDesc->id() << " @ " << bufferDesc->poolOffset(batchId)
                 << " @ " << buffAddr << std::endl;
    }

    PROPAGATE_ERROR_FAIL( NvDlaBuddyAlloc.deallocate(m_addr_mgr, reinterpret_cast<void*>(buffAddr)) );

#if 0
    // NO, can't do this.  We need a record of the alloc for
    // the memory/address list generator.
    bufferDesc->setAddress(NULL);
    bufferDesc->setPool(NULL);
    bufferDesc->setMemoryLoc(memory::LocationEnum::lUNKNOWN);
    bufferDesc->setPoolOffset(0);
    bufferDesc->clearAllocated();
#endif

fail:
    return e;
}