void LocalEpoch::EnterEpochRO(const uint64_t epoch_id) {
    epoch_lock_.Lock();
    // if this thread is never used or GC'd
    if (epoch_lower_bound_ == UINT64_MAX) {
      epoch_lower_bound_ = epoch_id - 1;
    } else if (epoch_lower_bound_ >= epoch_id) {
      epoch_lower_bound_ = epoch_id - 1;
    }

    if (epoch_map_.find(epoch_id) == epoch_map_.end()) {

      std::shared_ptr<Epoch> epoch_ptr(new Epoch(epoch_id, 1));

      epoch_queue_.push(epoch_ptr);
      epoch_map_[epoch_id] = epoch_ptr;

    } else {
      epoch_map_.at(epoch_id)->txn_count_++;
    }

    epoch_lock_.Unlock();
  }