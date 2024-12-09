bool TransportClientSocketPool::FindTopStalledGroup(Group** group,
                                                    GroupId* group_id) const {
  CHECK((group && group_id) || (!group && !group_id));
  Group* top_group = nullptr;
  const GroupId* top_group_id = nullptr;
  bool has_stalled_group = false;
  for (auto i = group_map_.begin(); i != group_map_.end(); ++i) {
    Group* curr_group = i->second;
    if (!curr_group->has_unbound_requests())
      continue;
    if (curr_group->CanUseAdditionalSocketSlot(max_sockets_per_group_)) {
      if (!group)
        return true;
      has_stalled_group = true;
      bool has_higher_priority =
          !top_group ||
          curr_group->TopPendingPriority() > top_group->TopPendingPriority();
      if (has_higher_priority) {
        top_group = curr_group;
        top_group_id = &i->first;
      }
    }
  }

  if (top_group) {
    CHECK(group);
    *group = top_group;
    *group_id = *top_group_id;
  } else {
    CHECK(!has_stalled_group);
  }
  return has_stalled_group;
}