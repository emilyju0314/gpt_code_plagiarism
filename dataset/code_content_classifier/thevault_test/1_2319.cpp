void SimFirmware::EscanResultSeen(const ScanResult& result_in) {
  // For now, the only IE we will include will be for the SSID
  size_t ssid_ie_size = 2 + result_in.ssid.len;

  // scan_result_size includes all BSS info structures (each including IEs). We (like the firmware)
  // only send one result back at a time.
  size_t scan_result_size = roundup(sizeof(brcmf_escan_result_le) + ssid_ie_size, 4);
  size_t scan_result_offset;

  brcmf_event_msg_be* msg_be;

  // Buffer is returned zeroed out with scan_result_offset set
  auto buf = CreateEventBuffer(scan_result_size, &msg_be, &scan_result_offset);

  // Set the scan-specific fields of the event message
  msg_be->event_type = htobe32(BRCMF_E_ESCAN_RESULT);
  msg_be->status = htobe32(BRCMF_E_STATUS_PARTIAL);

  uint8_t* buffer_data = buf->data();
  auto result_out = reinterpret_cast<brcmf_escan_result_le*>(&buffer_data[scan_result_offset]);
  result_out->buflen = scan_result_size;
  result_out->version = BRCMF_BSS_INFO_VERSION;
  result_out->sync_id = scan_state_.opts->sync_id;
  result_out->bss_count = 1;

  struct brcmf_bss_info_le* bss_info = &result_out->bss_info_le;
  bss_info->version = BRCMF_BSS_INFO_VERSION;

  // length of this record (includes IEs)
  bss_info->length = roundup(sizeof(brcmf_bss_info_le) + ssid_ie_size, 4);

  // channel
  bss_info->chanspec = channel_to_chanspec(&d11_inf_, &result_in.channel);

  // ssid
  ZX_ASSERT(sizeof(bss_info->SSID) == sizeof(result_in.ssid.ssid));
  ZX_ASSERT(result_in.ssid.len <= sizeof(result_in.ssid.ssid));
  bss_info->SSID_len = 0;  // SSID will go into an IE

  // bssid
  ZX_ASSERT(sizeof(bss_info->BSSID) == common::kMacAddrLen);
  memcpy(bss_info->BSSID, result_in.bssid.byte, common::kMacAddrLen);

  // IEs
  bss_info->ie_offset = sizeof(brcmf_bss_info_le);

  // IE: SSID
  size_t ie_offset = scan_result_offset + sizeof(brcmf_escan_result_le);
  size_t ie_len = 0;
  uint8_t* ie_data = &buffer_data[ie_offset];
  ie_data[ie_len++] = IEEE80211_ASSOC_TAG_SSID;
  ie_data[ie_len++] = result_in.ssid.len;
  memcpy(&ie_data[ie_len], result_in.ssid.ssid, result_in.ssid.len);
  ie_len += result_in.ssid.len;

  bss_info->ie_length = ie_len;

  // Wrap this in an event and send it back to the driver
  SendEventToDriver(std::move(buf));
}