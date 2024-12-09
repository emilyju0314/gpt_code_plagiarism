bool BufferPool::ProbeBufferPool(const pid_t pid, PageDesc *&ph) {
    auto it = mapping_table.find(pid);
    if (it == mapping_table.end())
        return false;
    ph = it->second;
    ph->Pin();
    replacer.Touch(ph);
    return true;
}