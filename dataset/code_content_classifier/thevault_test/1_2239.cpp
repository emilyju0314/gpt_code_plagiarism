void ActiveScanTest::RxProbeResp(const wlan_channel_t& channel, const common::MacAddr& src,
                                 const common::MacAddr& dst, const wlan_ssid_t& ssid) {
  GetFirwarePfnMac();
  EXPECT_NE(dst, sim_fw_mac_);
  EXPECT_EQ(dst, *sim_fw_pfn_mac_);
}