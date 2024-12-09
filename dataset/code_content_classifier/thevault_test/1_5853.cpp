Status PessimisticTransaction::ValidateSnapshot(
    ColumnFamilyHandle* column_family, const Slice& key,
    SequenceNumber* tracked_at_seq) {
  assert(snapshot_);

  SequenceNumber snap_seq = snapshot_->GetSequenceNumber();
  if (*tracked_at_seq <= snap_seq) {
    // If the key has been previous validated (or locked) at a sequence number
    // earlier than the current snapshot's sequence number, we already know it
    // has not been modified aftter snap_seq either.
    return Status::OK();
  }
  // Otherwise we have either
  // 1: tracked_at_seq == kMaxSequenceNumber, i.e., first time tracking the key
  // 2: snap_seq < tracked_at_seq: last time we lock the key was via
  // skip_validate option which means we had skipped ValidateSnapshot. In both
  // cases we should do ValidateSnapshot now.

  *tracked_at_seq = snap_seq;

  ColumnFamilyHandle* cfh =
      column_family ? column_family : db_impl_->DefaultColumnFamily();

  return TransactionUtil::CheckKeyForConflicts(
      db_impl_, cfh, key.ToString(), snap_seq, false /* cache_only */);
}