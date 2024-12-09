void TransactionLevelGCManager::DeleteTupleFromIndexes(ItemPointer *indirection) {
  // do nothing if indirection is null
  if (indirection == nullptr){
    return;
  }
  LOG_TRACE("Deleting indirection %p from index", indirection);
  
  ItemPointer location = *indirection;

  auto &manager = catalog::Manager::GetInstance();
  auto tile_group = manager.GetTileGroup(location.block);

  PL_ASSERT(tile_group != nullptr);

  storage::DataTable *table =
    dynamic_cast<storage::DataTable *>(tile_group->GetAbstractTable());
  PL_ASSERT(table != nullptr);

  // construct the expired version.
  expression::ContainerTuple<storage::TileGroup> expired_tuple(tile_group.get(), location.offset);

  // unlink the version from all the indexes.
  for (size_t idx = 0; idx < table->GetIndexCount(); ++idx) {
    auto index = table->GetIndex(idx);
    auto index_schema = index->GetKeySchema();
    auto indexed_columns = index_schema->GetIndexedColumns();

    // build key.
    std::unique_ptr<storage::Tuple> key(
      new storage::Tuple(index_schema, true));
    key->SetFromTuple(&expired_tuple, indexed_columns, index->GetPool());

    index->DeleteEntry(key.get(), indirection);

  }
}