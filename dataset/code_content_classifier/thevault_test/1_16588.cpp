bool EntryImpl::GrowUserBuffer(int index, int offset, int buf_len,
        bool truncate) 
{
    Addr address(entry_.Data()->data_addr[index]);

    if (offset + buf_len > kMaxBlockSize) {
        // The data has to be stored externally.
        if (address.is_initialized()) {
            if (address.is_separate_file())
                return true;
            if (!MoveToLocalBuffer(index))
                return false;
        }
        return Flush(index, offset + buf_len, true);
    }

    if (!address.is_initialized()) {
        //    DCHECK(user_buffers_[index].get());
        if (truncate)
            ClearInvalidData(user_buffers_[index].get(), 0, offset + buf_len);
        return true;
    }
    if (address.is_separate_file()) {
        if (!truncate)
            return true;
        //    return ImportSeparateFile(index, offset, buf_len);
    }

    // At this point we are dealing with data stored on disk, inside a block file.
    if (offset + buf_len <= address.BlockSize() * address.num_blocks())
        return true;

    // ... and the allocated block has to change.
    if (!MoveToLocalBuffer(index))
        return false;

    int clear_start = entry_.Data()->data_size[index];
    if (truncate)
        clear_start = std::min(clear_start, offset + buf_len);
    else if (offset < clear_start)
        clear_start = std::max(offset + buf_len, clear_start);

    // Clear the end of the buffer.
    ClearInvalidData(user_buffers_[index].get(), 0, clear_start);
    return true;
}