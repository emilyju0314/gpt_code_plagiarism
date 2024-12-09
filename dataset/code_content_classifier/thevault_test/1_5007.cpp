TEST_F(LibusbOverChromeUsbAsyncTransfersMultiThreadingTest,
       MAYBE_ControlTransfers) {
  const size_t kThreadCount = 10;

  std::vector<std::thread> threads;
  for (size_t thread_index = 0; thread_index < kThreadCount; ++thread_index) {
    threads.emplace_back([this, thread_index] {
      for (size_t transfer_index = thread_index;
           transfer_index <= kMaxTransferIndex;
           transfer_index += kThreadCount) {
        MockFunction<void(libusb_transfer_status)> transfer_callback[2];
        int transfer_completed[2] = {0};

        for (bool is_transfer_output : kBoolValues) {
          SetUpTransferCallbackMockExpectations(
              transfer_index, false, &transfer_callback[is_transfer_output],
              &transfer_completed[is_transfer_output]);
          StartAsyncControlTransfer(transfer_index, is_transfer_output,
                                    &transfer_callback[is_transfer_output]);
          AddTransferInFlight(transfer_index, is_transfer_output);
        }

        for (bool is_transfer_output : kBoolValues) {
          while (!transfer_completed[is_transfer_output]) {
            libusb_over_chrome_usb->LibusbHandleEventsCompleted(
                nullptr, &transfer_completed[is_transfer_output]);
          }
        }
      }
    });
  }

  for (;;) {
    size_t transfer_index;
    bool is_transfer_output;
    std::function<void()> chrome_usb_transfer_resolver;
    if (!WaitAndGetTransferInFlight(&transfer_index, &is_transfer_output,
                                    &chrome_usb_transfer_resolver)) {
      break;
    }
    chrome_usb_transfer_resolver();
  }

  for (size_t thread_index = 0; thread_index < kThreadCount; ++thread_index)
    threads[thread_index].join();
}