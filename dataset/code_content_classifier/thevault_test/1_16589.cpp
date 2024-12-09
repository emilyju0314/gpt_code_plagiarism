bool EntryImpl::Flush(int index, int size, bool async) 
{
    Addr address(entry_.Data()->data_addr[index]);
    //  DCHECK(user_buffers_[index].get());
    //  DCHECK(!address.is_initialized());

    if (!size)
        return true;

    if (!CreateDataBlock(index, size))
        return false;

    address.set_value(entry_.Data()->data_addr[index]);

    File* file = GetBackingFile(address, index);
    size_t len = entry_.Data()->data_size[index];
    size_t offset = 0;
    if (address.is_block_file())
        offset = address.start_block() * address.BlockSize() + kBlockHeaderSize;

    // We just told the backend to store len bytes for real.
    //  DCHECK(len == static_cast<size_t>(unreported_size_[index]));
    backend_->ModifyStorageSize(0, static_cast<int>(len));
    unreported_size_[index] = 0;

    if (!file)
        return false;

    // TODO(rvargas): figure out if it's worth to re-enable posting operations.
    // Right now it is only used from GrowUserBuffer, not the destructor, and
    // it is not accounted for from the point of view of the total number of
    // pending operations of the cache. It is also racing with the actual write
    // on the GrowUserBuffer path because there is no code to exclude the range
    // that is going to be written.

    async = false;
    if (!file->Write(user_buffers_[index].get(), len, offset)) //add by suyong
        return false;
    user_buffers_[index].reset(NULL);

    // The buffer is deleted from the PostWrite operation.
    user_buffers_[index].release();

    return true;
}