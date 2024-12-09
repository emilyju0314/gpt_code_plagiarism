zx_status_t SimFirmware::BusTxCtl(unsigned char* msg, unsigned int len) {
  brcmf_proto_bcdc_dcmd* dcmd;
  constexpr size_t hdr_size = sizeof(struct brcmf_proto_bcdc_dcmd);
  if (len < hdr_size) {
    BRCMF_DBG(SIM, "Message length (%u) smaller than BCDC header size (%zd)\n", len, hdr_size);
    return ZX_ERR_INVALID_ARGS;
  }
  dcmd = reinterpret_cast<brcmf_proto_bcdc_dcmd*>(msg);
  // The variable-length payload immediately follows the header
  uint8_t* data = reinterpret_cast<uint8_t*>(dcmd) + hdr_size;

  if (dcmd->len > (len - hdr_size)) {
    BRCMF_DBG(SIM, "BCDC total message length (%zd) exceeds buffer size (%u)\n",
              dcmd->len + hdr_size, len);
    return ZX_ERR_INVALID_ARGS;
  }

  zx_status_t status = ZX_OK;
  switch (dcmd->cmd) {
    // Get/Set a firmware IOVAR. This message is comprised of a NULL-terminated string
    // for the variable name, followed by the value to assign to it.
    case BRCMF_C_SET_VAR:
    case BRCMF_C_GET_VAR:
      status = BcdcVarOp(dcmd, data, len, dcmd->cmd == BRCMF_C_SET_VAR);
      break;
    case BRCMF_C_GET_REVINFO: {
      struct brcmf_rev_info_le rev_info;
      hw_.GetRevInfo(&rev_info);
      if (dcmd->len < sizeof(rev_info)) {
        BRCMF_DBG(
            SIM,
            "Insufficient space (%u bytes) in message buffer to save revision info (%zu bytes)\n",
            dcmd->len, sizeof(rev_info));
      }
      memcpy(data, &rev_info, sizeof(rev_info));
      bcdc_response_.Set(msg, len);
      break;
    }
    case BRCMF_C_GET_VERSION: {
      // GET_VERSION is a bit of a misnomer. It's really the 802.11 supported spec
      // (e.g., n or ac).
      if (dcmd->len < sizeof(kIoType)) {
        BRCMF_DBG(SIM,
                  "Insufficient space (%u bytes) in message buffer to save iotype "
                  "info (%zu bytes)\n",
                  dcmd->len, sizeof(kIoType));
      }
      std::memcpy(data, &kIoType, sizeof(kIoType));
      bcdc_response_.Set(msg, len);
      break;
    }
    case BRCMF_C_SET_PASSIVE_SCAN: {
      // Specify whether to use a passive scan by default (instead of an active scan)
      if (dcmd->len != sizeof(uint32_t)) {
        BRCMF_DBG(SIM, "Invalid args size to BRCMF_C_SET_PASSIVE_SCAN (expected %d, saw %d)\n",
                  sizeof(uint32_t), dcmd->len);
        return ZX_ERR_INVALID_ARGS;
      }
      uint32_t value = *(reinterpret_cast<uint32_t*>(data));
      default_passive_scan_ = value > 0;
      break;
    }
    case BRCMF_C_SET_SCAN_PASSIVE_TIME:
      if (dcmd->len != sizeof(default_passive_time_)) {
        BRCMF_DBG(SIM, "Invalid args size to BRCMF_C_SET_SCAN_PASSIVE_TIME (expected %d, saw %d)\n",
                  sizeof(default_passive_time_), dcmd->len);
        return ZX_ERR_INVALID_ARGS;
      }
      default_passive_time_ = *(reinterpret_cast<uint32_t*>(data));
      break;
    case BRCMF_C_SET_PM:
      if (dcmd->len != sizeof(power_mode_)) {
        BRCMF_DBG(SIM, "Invalid args size to BRCMF_C_SET_PM (expected %d, saw %d)\n",
                  sizeof(power_mode_), dcmd->len);
        return ZX_ERR_INVALID_ARGS;
      }
      power_mode_ = *(reinterpret_cast<int32_t*>(data));
      break;
    case BRCMF_C_SET_SCAN_CHANNEL_TIME:
    case BRCMF_C_SET_SCAN_UNASSOC_TIME:
      BRCMF_DBG(SIM, "Ignoring firmware message %d\n", dcmd->cmd);
      bcdc_response_.Set(msg, len);
      status = ZX_OK;
      break;
    default:
      BRCMF_DBG(SIM, "Unimplemented firmware message %d\n", dcmd->cmd);
      status = ZX_ERR_NOT_SUPPORTED;
      break;
  }
  return status;
}