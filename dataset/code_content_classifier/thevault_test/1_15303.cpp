NvDlaError engine_ast::Graph::prepareMemoryListEntries(Loadable *l)
{
    NvDlaError e = NvDlaSuccess;

    NvS16 memId = 0;
    NvS16 addrId = 0;

    vector< Loadable::MemoryListEntry > graphMemObjects;
    vector< Loadable::AddressListEntry > graphAddrObjects;
    vector< Loadable::TensorDescListEntry > tensorDescEntries;

    //
    // now we start
    //
    memId = 1;
    addrId = 1;

    //
    // each memory pool gets an id.  pools need to come before buffers
    // because buffers can and will use the pools' memory ids as needed.
    //
    PROPAGATE_ERROR_FAIL(addMemEntriesForPools(this, graphMemObjects, memId, graphAddrObjects, addrId));

    //
    // create memory id entries for non-pooled buffers
    //
    PROPAGATE_ERROR_FAIL(addMemEntriesForBuffers(this, graphMemObjects, tensorDescEntries, memId));

    //
    // surfaces generate address id entries
    //
    PROPAGATE_ERROR_FAIL(addAddrEntriesForSurfaces(l, this, graphAddrObjects, addrId));

    l->setMemoryListEntries(graphMemObjects);
    l->setAddressListEntries(graphAddrObjects);
    l->setTensorDescListEntries(tensorDescEntries);

fail:
    return e;
}