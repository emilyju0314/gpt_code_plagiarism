static bool RepMemoryUsageLeaf(const CordRep* rep, size_t* total_mem_usage) {
  if (rep->tag >= FLAT) {
    *total_mem_usage += rep->flat()->AllocatedSize();
    return true;
  }
  if (rep->tag == EXTERNAL) {
    *total_mem_usage += sizeof(CordRepConcat) + rep->length;
    return true;
  }
  return false;
}