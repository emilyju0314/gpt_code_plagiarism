static zx_status_t brcmf_get_meta_data(brcmf_if* ifp, wifi_config_t* config) {
  zx_status_t err;
  size_t actual;
  err = brcmf_bus_get_wifi_metadata(ifp->drvr->bus_if, config, sizeof(wifi_config_t), &actual);
  if (err != ZX_OK) {
    BRCMF_ERR("get metadata failed, err: %d\n", err);
    memset(config, 0, sizeof(*config));
    return err;
  }
  if (actual != sizeof(*config)) {
    BRCMF_ERR("meta data size err exp:%d act: %lu\n", sizeof(*config), actual);
    memset(config, 0, sizeof(*config));
    return ZX_ERR_IO;
  }
  return ZX_OK;
}