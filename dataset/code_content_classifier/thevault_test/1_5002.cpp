TEST_P(LibusbOverChromeUsbSingleTransferTest, SyncControlTransfer) {
  SetUpMockForSyncControlTransfer(GetParam().transfer_index,
                                  GetParam().is_transfer_output);
  TestSyncControlTransfer(GetParam().transfer_index,
                          GetParam().is_transfer_output);
}