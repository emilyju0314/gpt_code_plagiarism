TEST_P(LibusbOverChromeUsbSingleTransferTest,
       AsyncTransferCompletionAfterCancellation) {
  if (GetParam().is_transfer_output) {
    // Cancellation of an output transfer is not supported, so the whole test
    // makes no sense.
    return;
  }

  const std::function<void()> first_chrome_usb_transfer_resolver =
      SetUpMockForAsyncControlTransfer(GetParam().transfer_index,
                                       GetParam().is_transfer_output);
  const std::function<void()> second_chrome_usb_transfer_resolver =
      SetUpMockForAsyncControlTransfer(GetParam().transfer_index,
                                       GetParam().is_transfer_output);

  MockFunction<void(libusb_transfer_status)> first_transfer_callback;
  libusb_transfer* const first_transfer = StartAsyncControlTransfer(
      GetParam().transfer_index, GetParam().is_transfer_output,
      &first_transfer_callback);

  MockFunction<void(libusb_transfer_status)> second_transfer_callback;
  StartAsyncControlTransfer(GetParam().transfer_index,
                            GetParam().is_transfer_output,
                            &second_transfer_callback);

  EXPECT_EQ(LIBUSB_SUCCESS,
            libusb_over_chrome_usb->LibusbCancelTransfer(first_transfer));

  first_chrome_usb_transfer_resolver();

  ASSERT_TRUE(Mock::VerifyAndClearExpectations(&first_transfer_callback));
  ASSERT_TRUE(Mock::VerifyAndClearExpectations(&second_transfer_callback));
  SetUpTransferCallbackMockExpectations(GetParam().transfer_index, true,
                                        &first_transfer_callback);
  SetUpTransferCallbackMockExpectations(GetParam().transfer_index, false,
                                        &second_transfer_callback);
  libusb_over_chrome_usb->LibusbHandleEvents(nullptr);
  libusb_over_chrome_usb->LibusbHandleEvents(nullptr);
}