Status PessimisticTransaction::TryLock(ColumnFamilyHandle* column_family,
                                       const Slice& key, bool read_only,
                                       bool exclusive, bool skip_validate) {
  Status s;
  if (UNLIKELY(skip_concurrency_control_)) {
    return s;
  }
  uint32_t cfh_id = GetColumnFamilyID(column_family);
  std::string key_str = key.ToString();
  bool previously_locked;
  bool lock_upgrade = false;

  // lock this key if this transactions hasn't already locked it
  SequenceNumber tracked_at_seq = kMaxSequenceNumber;

  const auto& tracked_keys = GetTrackedKeys();
  const auto tracked_keys_cf = tracked_keys.find(cfh_id);
  if (tracked_keys_cf == tracked_keys.end()) {
    previously_locked = false;
  } else {
    auto iter = tracked_keys_cf->second.find(key_str);
    if (iter == tracked_keys_cf->second.end()) {
      previously_locked = false;
    } else {
      if (!iter->second.exclusive && exclusive) {
        lock_upgrade = true;
      }
      previously_locked = true;
      tracked_at_seq = iter->second.seq;
    }
  }

  // Lock this key if this transactions hasn't already locked it or we require
  // an upgrade.
  if (!previously_locked || lock_upgrade) {
    s = txn_db_impl_->TryLock(this, cfh_id, key_str, exclusive);
  }

  SetSnapshotIfNeeded();

  // Even though we do not care about doing conflict checking for this write,
  // we still need to take a lock to make sure we do not cause a conflict with
  // some other write.  However, we do not need to check if there have been
  // any writes since this transaction's snapshot.
  // TODO(agiardullo): could optimize by supporting shared txn locks in the
  // future
  if (skip_validate || snapshot_ == nullptr) {
    // Need to remember the earliest sequence number that we know that this
    // key has not been modified after.  This is useful if this same
    // transaction
    // later tries to lock this key again.
    if (tracked_at_seq == kMaxSequenceNumber) {
      // Since we haven't checked a snapshot, we only know this key has not
      // been modified since after we locked it.
      // Note: when last_seq_same_as_publish_seq_==false this is less than the
      // latest allocated seq but it is ok since i) this is just a heuristic
      // used only as a hint to avoid actual check for conflicts, ii) this would
      // cause a false positive only if the snapthot is taken right after the
      // lock, which would be an unusual sequence.
      tracked_at_seq = db_->GetLatestSequenceNumber();
    }
  } else {
    // If a snapshot is set, we need to make sure the key hasn't been modified
    // since the snapshot.  This must be done after we locked the key.
    // If we already have validated an earilier snapshot it must has been
    // reflected in tracked_at_seq and ValidateSnapshot will return OK.
    if (s.ok()) {
      s = ValidateSnapshot(column_family, key, &tracked_at_seq);

      if (!s.ok()) {
        // Failed to validate key
        if (!previously_locked) {
          // Unlock key we just locked
          if (lock_upgrade) {
            s = txn_db_impl_->TryLock(this, cfh_id, key_str,
                                      false /* exclusive */);
            assert(s.ok());
          } else {
            txn_db_impl_->UnLock(this, cfh_id, key.ToString());
          }
        }
      }
    }
  }

  if (s.ok()) {
    // We must track all the locked keys so that we can unlock them later. If
    // the key is already locked, this func will update some stats on the
    // tracked key. It could also update the tracked_at_seq if it is lower than
    // the existing trackey seq.
    TrackKey(cfh_id, key_str, tracked_at_seq, read_only, exclusive);
  }

  return s;
}