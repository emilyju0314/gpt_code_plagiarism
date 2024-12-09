TEST_F(LibusbOverChromeUsbTransfersTest,
       MAYBE_SyncControlTransfersWithMultiThreading) {
  const size_t kMaxTransferIndex = 1000;
  const size_t kThreadCount = 10;

  for (size_t index = 0; index <= kMaxTransferIndex; ++index) {
    for (bool is_transfer_output : kBoolValues)
      SetUpMockForSyncControlTransfer(index, is_transfer_output);
  }

  std::vector<std::thread> threads;
  for (size_t thread_index = 0; thread_index < kThreadCount; ++thread_index) {
    threads.emplace_back([this, thread_index] {
      for (size_t transfer_index = thread_index;
           transfer_index <= kMaxTransferIndex;
           transfer_index += kThreadCount) {
        for (bool is_transfer_output : kBoolValues)
          TestSyncControlTransfer(transfer_index, is_transfer_output);
      }
    });
  }
  for (size_t thread_index = 0; thread_index < kThreadCount; ++thread_index)
    threads[thread_index].join();
}