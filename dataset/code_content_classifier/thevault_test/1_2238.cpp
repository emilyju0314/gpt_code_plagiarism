void ActiveScanTest::RxProbeReq(const wlan_channel_t& channel, const common::MacAddr& src) {
  GetFirwarePfnMac();
  EXPECT_NE(src, sim_fw_mac_);
  EXPECT_EQ(src, *sim_fw_pfn_mac_);
}