zx_status_t brcmf_set_country(brcmf_pub* drvr, const wlanphy_country_t* country) {
  struct brcmf_if* ifp = brcmf_get_ifp(drvr, 0);
  wifi_config_t config;
  struct brcmf_fil_country_le ccreq;
  zx_status_t err;
  int32_t fw_err = 0;
  const unsigned char* code = country->alpha2;
  int i;

  BRCMF_DBG(TRACE, "Enter: code=%c%c\n", code[0], code[1]);
  // Get Broadcom WiFi Metadata by calling the bus specific function
  err = brcmf_get_meta_data(ifp, &config);
  if (err != ZX_OK) {
    return err;
  }

  // This is the default value in case the relevant entry is not found in the table.
  ccreq.rev = 0;
  // Search through the table until a valid or Null entry is found
  for (i = 0; i < MAX_CC_TABLE_ENTRIES; i++) {
    if (config.cc_table[i].cc_abbr[0] == 0) {
      BRCMF_ERR("ccode %c%c not found in table\n", code[0], code[1]);
      return ZX_ERR_NOT_FOUND;
    }
    if (memcmp(config.cc_table[i].cc_abbr, code, WLANPHY_ALPHA2_LEN) == 0) {
      ccreq.rev = config.cc_table[i].cc_rev;
      break;
    }
  }
  // It appears brcm firmware expects ccode and country_abbrev to have the same value
  ccreq.ccode[0] = code[0];
  ccreq.ccode[1] = code[1];
  ccreq.ccode[2] = 0;
  ccreq.country_abbrev[0] = code[0];
  ccreq.country_abbrev[1] = code[1];
  ccreq.country_abbrev[2] = 0;

  // Log out the country code settings for reference
  BRCMF_ERR("Country code set ccode %s, abbrev %s, rev %d\n", ccreq.ccode, ccreq.country_abbrev,
            ccreq.rev);
  // Set the country info in firmware
  err = brcmf_fil_iovar_data_set(ifp, "country", &ccreq, sizeof(ccreq), &fw_err);
  if (err != ZX_OK) {
    BRCMF_ERR("Firmware rejected country setting: %s fw err %s\n", zx_status_get_string(err),
              brcmf_fil_get_errstr(fw_err));
  }
  return err;
}