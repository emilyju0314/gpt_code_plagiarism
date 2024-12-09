void AstroDisplay::PopulatePanelType() {
  uint8_t pt;
  if ((gpio_config_in(&gpio_, GPIO_NO_PULL) == ZX_OK) && (gpio_read(&gpio_, &pt) == ZX_OK)) {
    panel_type_ = pt;
    if (board_info_.pid == PDEV_PID_ASTRO) {
      DISP_INFO("Detected panel type = %s (%d)\n", panel_type_ ? "P070ACB_FT" : "TV070WSM_FT",
                panel_type_);
    } else if (board_info_.pid == PDEV_PID_SHERLOCK) {
      DISP_INFO("Detected panel type = %s (%d)\n", panel_type_ ? "G101B158_FT" : "TV101WXM_FT",
                panel_type_);
      panel_type_ = static_cast<uint8_t>(pt + PANEL_TV101WXM_FT);
    } else {
      DISP_ERROR("Panel detection attempted on Unsupported hardware\n");
      ZX_ASSERT(0);
    }
  } else {
    panel_type_ = PANEL_UNKNOWN;
    DISP_ERROR("Failed to detect a valid panel\n");
  }
}