void AssocTest::RxAssocReq(const wlan_channel_t& channel, const common::MacAddr& src,
                           const common::MacAddr& bssid) {
  if (context_.on_assoc_req_callback) {
    (*context_.on_assoc_req_callback)();
  }
}