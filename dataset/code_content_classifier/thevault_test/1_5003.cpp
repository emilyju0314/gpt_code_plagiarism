TEST_P(LibusbOverChromeUsbSingleTransferTest, AsyncControlTransfer) {
  const std::function<void()> chrome_usb_transfer_resolver =
      SetUpMockForAsyncControlTransfer(GetParam().transfer_index,
                                       GetParam().is_transfer_output);

  MockFunction<void(libusb_transfer_status)> transfer_callback;
  StartAsyncControlTransfer(GetParam().transfer_index,
                            GetParam().is_transfer_output, &transfer_callback);

  chrome_usb_transfer_resolver();

  ASSERT_TRUE(Mock::VerifyAndClearExpectations(&transfer_callback));
  SetUpTransferCallbackMockExpectations(GetParam().transfer_index, false,
                                        &transfer_callback);
  libusb_over_chrome_usb->LibusbHandleEvents(nullptr);
}