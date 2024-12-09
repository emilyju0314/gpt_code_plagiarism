cpu_mask_t GetEffectiveCpuMask(cpu_mask_t active_mask, const thread_t* thread) {
  // The thread may run on any active CPU allowed by both its hard and
  // soft CPU affinity.
  const cpu_mask_t soft_affinity = thread->soft_affinity;
  const cpu_mask_t hard_affinity = thread->hard_affinity;
  const cpu_mask_t available_mask = active_mask & soft_affinity & hard_affinity;

  // Return the mask honoring soft affinity if it is viable, otherwise ignore
  // soft affinity and honor only hard affinity.
  if (likely(available_mask != 0)) {
    return available_mask;
  }

  return active_mask & hard_affinity;
}