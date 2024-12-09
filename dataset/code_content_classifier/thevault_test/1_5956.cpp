void CreateVirtualEvents(EventNodeMap* event_node_map,
                         VirtualEventContainer* virtual_event_container) {
  VirtualEventNodeMap virtual_event_node_map;
  auto executor_event_node_list =
      gtl::FindOrNull(*event_node_map, HostEventType::kExecutorStateProcess);
  if (!executor_event_node_list) return;
  for (auto& executor_event_node : *executor_event_node_list) {
    const XStat* step_id_stat =
        executor_event_node->GetContextStat(StatType::kStepId);
    const XStat* iter_num_stat =
        executor_event_node->GetContextStat(StatType::kIterNum);
    if (!step_id_stat || !iter_num_stat) continue;
    int64 step_id = step_id_stat->int64_value();
    int64 iter_num = iter_num_stat->int64_value();
    // Process the event with nonzero iter_num only to filter out the events
    // related to tf.data.
    // TODO(jihochoi): Filter out tf.data events more reliably.
    if (!iter_num) continue;
    EventNode*& virtual_event_node = virtual_event_node_map[step_id][iter_num];
    if (!virtual_event_node) {
      std::unique_ptr<XEvent> new_virtual_event =
          CreateVirtualEvent(*step_id_stat, *iter_num_stat);
      auto new_virtual_event_node = absl::make_unique<EventNode>(
          &executor_event_node->GetPlaneVisitor(), new_virtual_event.get());
      // virtual_event_container keeps new_virtual_event alive.
      virtual_event_container->push_back(std::move(new_virtual_event));
      virtual_event_node = new_virtual_event_node.get();
      // event_node_map keeps new_virtual_event_node alive.
      (*event_node_map)[HostEventType::kHostTrainingLoopIteration].push_back(
          std::move(new_virtual_event_node));
    }
    virtual_event_node->AddChild(executor_event_node.get());
  }
}