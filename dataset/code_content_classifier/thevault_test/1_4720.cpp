void ContextSwitchManager::ProcessContextSwitch(uint16_t cpu, uint32_t old_tid, uint32_t new_tid,
                                                uint64_t timestamp_ns) {
  std::optional<ContextSwitch> last_context_switch = std::nullopt;
  ++stats_.num_processed_cpu_events_;
  auto last_context_switch_it = last_context_switch_by_cpu_.find(cpu);
  if (last_context_switch_it != last_context_switch_by_cpu_.end()) {
    last_context_switch = last_context_switch_it->second;
  }

  ContextSwitch new_context_switch{timestamp_ns, old_tid, new_tid};
  last_context_switch_by_cpu_[cpu] = new_context_switch;
  if (!last_context_switch.has_value()) {
    return;
  }

  CHECK(new_context_switch.timestamp_ns >= last_context_switch->timestamp_ns);

  if (last_context_switch->new_tid == new_context_switch.old_tid) {
    orbit_grpc_protos::SchedulingSlice scheduling_slice;
    uint32_t tid = last_context_switch->new_tid;
    auto pid_it = pid_by_tid_.find(tid);
    uint32_t pid = pid_it != pid_by_tid_.end() ? pid_it->second : orbit_base::kInvalidProcessId;
    scheduling_slice.set_pid(pid);
    scheduling_slice.set_tid(tid);
    scheduling_slice.set_core(cpu);
    scheduling_slice.set_duration_ns(new_context_switch.timestamp_ns -
                                     last_context_switch->timestamp_ns);
    scheduling_slice.set_out_timestamp_ns(new_context_switch.timestamp_ns);

    ++stats_.num_scheduling_slices;
    if (pid == orbit_base::kInvalidProcessId) {
      ++stats_.num_scheduling_slices_with_invalid_pid;
      stats_.tid_witout_pid_set_.insert(tid);
    }

    listener_->OnSchedulingSlice(scheduling_slice);
  } else {
    // Can happen on thread creation or if we are losing events.
    ++stats_.num_tid_mismatches_;
  }
}