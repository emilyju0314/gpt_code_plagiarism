TEST_P(LibusbOverChromeUsbSingleTransferTest, AsyncTransferCancellation) {
  const std::function<void()> chrome_usb_transfer_resolver =
      SetUpMockForAsyncControlTransfer(GetParam().transfer_index,
                                       GetParam().is_transfer_output);

  MockFunction<void(libusb_transfer_status)> transfer_callback;
  libusb_transfer* const transfer = StartAsyncControlTransfer(
      GetParam().transfer_index, GetParam().is_transfer_output,
      &transfer_callback);

  // Output transfer cancellation is never successfull
  const bool is_cancellation_successful = !GetParam().is_transfer_output;

  if (is_cancellation_successful) {
    EXPECT_EQ(LIBUSB_SUCCESS,
              libusb_over_chrome_usb->LibusbCancelTransfer(transfer));
  } else {
    EXPECT_NE(LIBUSB_SUCCESS,
              libusb_over_chrome_usb->LibusbCancelTransfer(transfer));
  }

  // Second attempt to cancel a transfer is never successful
  EXPECT_NE(LIBUSB_SUCCESS,
            libusb_over_chrome_usb->LibusbCancelTransfer(transfer));

  if (!is_cancellation_successful) {
    // Resolve the chrome.usb transfer if the transfer was an output transfer,
    // because its cancellation was unsuccessful.
    chrome_usb_transfer_resolver();
  }

  ASSERT_TRUE(Mock::VerifyAndClearExpectations(&transfer_callback));
  SetUpTransferCallbackMockExpectations(GetParam().transfer_index,
                                        is_cancellation_successful,
                                        &transfer_callback);
  libusb_over_chrome_usb->LibusbHandleEvents(nullptr);
}