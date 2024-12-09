void TransactionLevelGCManager::AddToRecycleMap(std::shared_ptr<GarbageContext> garbage_ctx) {
  for (auto &entry : *(garbage_ctx->gc_set_.get())) {

    auto &manager = catalog::Manager::GetInstance();
    auto tile_group = manager.GetTileGroup(entry.first);

    // During the resetting, a table may be deconstructed because of the DROP TABLE request
    if (tile_group == nullptr) {
      return;
    }

    PL_ASSERT(tile_group != nullptr);

    storage::DataTable *table =
      dynamic_cast<storage::DataTable *>(tile_group->GetAbstractTable());
    PL_ASSERT(table != nullptr);

    oid_t table_id = table->GetOid();

    for (auto &element : entry.second) {

      // as this transaction has been committed, we should reclaim older versions.
      ItemPointer location(entry.first, element.first); 
      
      // If the tuple being reset no longer exists, just skip it
      if (ResetTuple(location) == false) {
        continue;
      }
      // if the entry for table_id exists.
      if (recycle_queue_map_.find(table_id) != recycle_queue_map_.end()) {
        recycle_queue_map_[table_id]->Enqueue(location);
      }

    }
  }

}