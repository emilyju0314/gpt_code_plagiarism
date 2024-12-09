void BindSparseUtils::ExpandBindSparseInfo(
    ExpandedBindSparseInfo* bind_sparse_expand_info) {
  bind_sparse_expand_info->submit_infos.clear();
  bind_sparse_expand_info->timeline_semaphore_infos.clear();
  VkSubmitInfo vk_submit_info = {};
  vk_submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
  VkTimelineSemaphoreSubmitInfoKHR vk_timeline_semaphore_submit_info = {};
  vk_timeline_semaphore_submit_info.sType =
      VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR;
  auto& packed_bind_sparse_info =
      bind_sparse_expand_info->packed_bind_sparse_info;
  for (uint32_t i = 0; i < packed_bind_sparse_info->bind_info_count; i++) {
    const VkTimelineSemaphoreSubmitInfoKHR* timeline_semaphore_info =
        FindOnChain<VkTimelineSemaphoreSubmitInfoKHR,
                    VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR>(
            packed_bind_sparse_info->bind_infos[i].pNext);

    // If the bind info has a wait operation on a binary semaphore do a
    // vkQueueSubmit.
    if (BindSparseInfoWaitsOnBinarySemaphores(
            &packed_bind_sparse_info->bind_infos[i],
            packed_bind_sparse_info->semaphore_tracker)) {
      bind_sparse_expand_info->queue_operation_types.push_back(kQueueSubmit);
      bind_sparse_expand_info->submit_infos.push_back(vk_submit_info);
      auto& submit_info = bind_sparse_expand_info->submit_infos.back();
      if (timeline_semaphore_info) {
        bind_sparse_expand_info->has_timeline_semaphore_info.push_back(true);
        bind_sparse_expand_info->timeline_semaphore_infos.push_back(
            vk_timeline_semaphore_submit_info);
        auto& tsinfo = bind_sparse_expand_info->timeline_semaphore_infos.back();
        tsinfo.waitSemaphoreValueCount =
            timeline_semaphore_info->waitSemaphoreValueCount;
        tsinfo.pWaitSemaphoreValues =
            timeline_semaphore_info->pWaitSemaphoreValues;
      } else {
        bind_sparse_expand_info->has_timeline_semaphore_info.push_back(false);
      }
      submit_info.waitSemaphoreCount =
          packed_bind_sparse_info->bind_infos[i].waitSemaphoreCount;
      submit_info.pWaitSemaphores =
          packed_bind_sparse_info->bind_infos[i].pWaitSemaphores;
      // Since waiting on a binary semaphore resets the semaphore, we signal
      // the binary semaphores again. We keep track of those semaphores here
      // and add them to the submit before consumption to avoid issues related
      // to pointing to vector members that may resize.
      bind_sparse_expand_info->wait_binary_semaphores.push_back(
          std::vector<VkSemaphore>());
      auto& wbsemaphores =
          bind_sparse_expand_info->wait_binary_semaphores.back();
      GetWaitBinarySemaphores(&packed_bind_sparse_info->bind_infos[i],
                              packed_bind_sparse_info->semaphore_tracker,
                              &wbsemaphores);
    }

    // Always do the sparse binding.
    bind_sparse_expand_info->queue_operation_types.push_back(kQueueBindSparse);

    // If the bind info has a signal operation on a semaphore do a
    // vkQueueSubmit.
    if (packed_bind_sparse_info->bind_infos[i].signalSemaphoreCount > 0) {
      bind_sparse_expand_info->queue_operation_types.push_back(kQueueSubmit);
      bind_sparse_expand_info->submit_infos.push_back(vk_submit_info);
      auto& submit_info = bind_sparse_expand_info->submit_infos.back();
      if (timeline_semaphore_info) {
        bind_sparse_expand_info->has_timeline_semaphore_info.push_back(true);
        bind_sparse_expand_info->timeline_semaphore_infos.push_back(
            vk_timeline_semaphore_submit_info);
        auto& tsinfo = bind_sparse_expand_info->timeline_semaphore_infos.back();
        tsinfo.signalSemaphoreValueCount =
            timeline_semaphore_info->signalSemaphoreValueCount;
        tsinfo.pSignalSemaphoreValues =
            timeline_semaphore_info->pSignalSemaphoreValues;
      } else {
        bind_sparse_expand_info->has_timeline_semaphore_info.push_back(false);
      }
      submit_info.signalSemaphoreCount =
          packed_bind_sparse_info->bind_infos[i].signalSemaphoreCount;
      submit_info.pSignalSemaphores =
          packed_bind_sparse_info->bind_infos[i].pSignalSemaphores;
    }
  }
}