zx_status_t SimFirmware::BcdcVarOp(brcmf_proto_bcdc_dcmd* dcmd, uint8_t* data, size_t len,
                                   bool is_set) {
  zx_status_t status = ZX_OK;

  char* str_begin = reinterpret_cast<char*>(data);
  uint8_t* str_end = static_cast<uint8_t*>(memchr(str_begin, '\0', dcmd->len));
  if (str_end == nullptr) {
    BRCMF_DBG(SIM, "SET_VAR: iovar name not null-terminated\n");
    return ZX_ERR_INVALID_ARGS;
  }

  size_t str_len = str_end - data;

  // IovarsSet returns the input unchanged
  // IovarsGet modifies the buffer in-place
  if (is_set) {
    void* value_start = str_end + 1;
    size_t value_len = dcmd->len - (str_len + 1);
    status = IovarsSet(str_begin, value_start, value_len);
  } else {
    status = IovarsGet(str_begin, data, dcmd->len);
  }

  if (status == ZX_OK) {
    bcdc_response_.Set(reinterpret_cast<uint8_t*>(dcmd), len);
  } else {
    // Return empty message on failure
    bcdc_response_.Clear();
  }
  return status;
}