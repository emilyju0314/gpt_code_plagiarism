void ClearInvalidData(char* buffer, int offset, int valid_len)
{
    //  DCHECK(offset >= 0);
    //  DCHECK(valid_len >= 0);
    //  DCHECK(disk_cache::kMaxBlockSize >= offset + valid_len);
    if (offset)
        memset(buffer, 0, offset);
    int end = disk_cache::kMaxBlockSize - offset - valid_len;
    if (end)
        memset(buffer + offset + valid_len, 0, end);
}