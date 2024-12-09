static void brcmf_set_init_cfg_params(brcmf_if* ifp) {
  int i;
  int32_t fw_err;
  zx_status_t err;
  wifi_config_t config;

  err = brcmf_get_meta_data(ifp, &config);
  if (err != ZX_OK) {
    return;
  }
  // Go through the table until a null entry is found
  for (i = 0; i < MAX_IOVAR_ENTRIES; i++) {
    switch (config.iovar_table[i].iovar_type) {
      case IOVAR_STR_TYPE: {
        uint32_t cur_val;

        // First, get the current value (for debugging)
        err = brcmf_fil_iovar_int_get(ifp, config.iovar_table[i].iovar_str, &cur_val, &fw_err);
        if (err != ZX_OK) {
          BRCMF_ERR("iovar get error: %s, fw err %s\n", config.iovar_table[i].iovar_str,
                    brcmf_fil_get_errstr(fw_err));
        } else {
          BRCMF_INFO("iovar %s get: %d new: %d\n", config.iovar_table[i].iovar_str, cur_val,
                     config.iovar_table[i].val);
          err = brcmf_fil_iovar_int_set(ifp, config.iovar_table[i].iovar_str,
                                        config.iovar_table[i].val, &fw_err);
          if (err != ZX_OK) {
            BRCMF_ERR("iovar set error: %s, fw err %s\n", config.iovar_table[i].iovar_str,
                      brcmf_fil_get_errstr(fw_err));
          }
        }
        break;
      }
      case IOVAR_CMD_TYPE: {
        err =
            brcmf_fil_cmd_data_set(ifp, config.iovar_table[i].iovar_cmd, &config.iovar_table[i].val,
                                   sizeof(config.iovar_table[i].val), &fw_err);
        if (err != ZX_OK) {
          BRCMF_ERR("iovar cmd set error: %d, fw err %s\n", config.iovar_table[i].iovar_cmd,
                    brcmf_fil_get_errstr(fw_err));
        }
      }
      case IOVAR_LIST_END_TYPE:
        // End of list, done setting iovars
        return;
    }
  }
}