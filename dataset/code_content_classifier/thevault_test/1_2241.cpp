zx_status_t Sherlock::EnableWifi32K() {
  // Configure SOC_WIFI_LPO_32k768 pin for PWM_E
  zx_status_t status = gpio_impl_.SetAltFunction(SOC_WIFI_LPO_32k768, 1);
  if (status != ZX_OK) {
    return status;
  }

  zx::bti bti;
  status = iommu_.GetBti(BTI_BOARD, 0, &bti);
  if (status != ZX_OK) {
    zxlogf(ERROR, "%s: GetBti failed: %d\n", __func__, status);
    return status;
  }

  return ZX_OK;
}