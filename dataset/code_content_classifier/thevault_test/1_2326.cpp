thread_t* Scheduler::FindEarliestEligibleThread(RunQueue* run_queue, SchedTime eligible_time) {
  // Early out if there is no eligible thread.
  if (run_queue->is_empty() || run_queue->front().scheduler_state.start_time_ > eligible_time) {
    return nullptr;
  }

  auto node = run_queue->root();
  auto subtree = run_queue->end();
  auto path = run_queue->end();

  // Descend the tree, with |node| following the path from the root to a leaf,
  // such that the path partitions the tree into two parts: the nodes on the
  // left represent eligible tasks, while the nodes on the right represent tasks
  // that are not eligible. Eligible tasks are both in the left partition and
  // along the search path, tracked by |path|.
  while (node) {
    if (node->scheduler_state.start_time_ <= eligible_time) {
      if (!path || path->scheduler_state.finish_time_ > node->scheduler_state.finish_time_) {
        path = node;
      }

      if (auto left = node.left();
          !subtree || (left && subtree->scheduler_state.min_finish_time_ >
                                   left->scheduler_state.min_finish_time_)) {
        subtree = left;
      }

      node = node.right();
    } else {
      node = node.left();
    }
  }

  if (!subtree || subtree->scheduler_state.min_finish_time_ >= path->scheduler_state.finish_time_) {
    return path.CopyPointer();
  }

  // Find the node with the earliest finish time among the decendents of the
  // subtree with the smallest minimum finish time.
  node = subtree;
  do {
    if (subtree->scheduler_state.min_finish_time_ == node->scheduler_state.finish_time_) {
      return node.CopyPointer();
    }

    if (auto left = node.left();
        left && node->scheduler_state.min_finish_time_ == left->scheduler_state.min_finish_time_) {
      node = left;
    } else {
      node = node.right();
    }
  } while (node);

  return nullptr;
}