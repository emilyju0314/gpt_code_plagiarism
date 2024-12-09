ItemPointer TransactionLevelGCManager::ReturnFreeSlot(const oid_t &table_id) {
  // for catalog tables, we directly return invalid item pointer.
  if (recycle_queue_map_.find(table_id) == recycle_queue_map_.end()) {
    return INVALID_ITEMPOINTER;
  }
  ItemPointer location;
  PL_ASSERT(recycle_queue_map_.find(table_id) != recycle_queue_map_.end());
  auto recycle_queue = recycle_queue_map_[table_id];

  if (recycle_queue->Dequeue(location) == true) {
    LOG_TRACE("Reuse tuple(%u, %u) in table %u", location.block,
              location.offset, table_id);
    return location;
  }
  return INVALID_ITEMPOINTER;
}