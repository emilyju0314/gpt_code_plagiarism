zx_status_t AstroDisplay::Bind() {
  composite_protocol_t composite;

  auto status = device_get_protocol(parent_, ZX_PROTOCOL_COMPOSITE, &composite);
  if (status != ZX_OK) {
    DISP_ERROR("Could not get composite protocol\n");
    return status;
  }

  size_t actual;
  composite_get_components(&composite, components_, fbl::count_of(components_), &actual);
  if (actual != fbl::count_of(components_)) {
    DISP_ERROR("could not get components\n");
    return ZX_ERR_NOT_SUPPORTED;
  }

  status = device_get_protocol(components_[COMPONENT_PDEV], ZX_PROTOCOL_PDEV, &pdev_);
  if (status != ZX_OK) {
    DISP_ERROR("Could not get PDEV protocol\n");
    return status;
  }

  dsi_impl_protocol_t dsi;
  status = device_get_protocol(components_[COMPONENT_DSI], ZX_PROTOCOL_DSI_IMPL, &dsi);
  if (status != ZX_OK) {
    DISP_ERROR("Could not get DSI_IMPL protocol\n");
    return status;
  }
  dsiimpl_ = &dsi;

  // Get board info
  status = pdev_get_board_info(&pdev_, &board_info_);
  if (status != ZX_OK) {
    DISP_ERROR("Could not obtain board info\n");
    return status;
  }

  if (board_info_.pid == PDEV_PID_ASTRO) {
    width_ = ASTRO_DISPLAY_WIDTH;
    height_ = ASTRO_DISPLAY_HEIGHT;
  } else if (board_info_.pid == PDEV_PID_SHERLOCK) {
    width_ = SHERLOCK_DISPLAY_WIDTH;
    height_ = SHERLOCK_DISPLAY_HEIGHT;
  } else {
    DISP_ERROR("Running on Unsupported hardware. Use at your own risk\n");
  }

  // Obtain GPIO Protocol for Panel reset
  status = device_get_protocol(components_[COMPONENT_PANEL_GPIO], ZX_PROTOCOL_GPIO, &gpio_);
  if (status != ZX_OK) {
    DISP_ERROR("Could not obtain GPIO protocol.\n");
    return status;
  }

  status = device_get_protocol(components_[COMPONENT_SYSMEM], ZX_PROTOCOL_SYSMEM, &sysmem_);
  if (status != ZX_OK) {
    DISP_ERROR("Could not get Display SYSMEM protocol\n");
    return status;
  }

  status = device_get_protocol(components_[COMPONENT_CANVAS], ZX_PROTOCOL_AMLOGIC_CANVAS, &canvas_);
  if (status != ZX_OK) {
    DISP_ERROR("Could not obtain CANVAS protocol\n");
    return status;
  }

  status = pdev_get_bti(&pdev_, 0, bti_.reset_and_get_address());
  if (status != ZX_OK) {
    DISP_ERROR("Could not get BTI handle\n");
    return status;
  }

  // Setup Display Interface
  status = SetupDisplayInterface();
  if (status != ZX_OK) {
    DISP_ERROR("Astro display setup failed! %d\n", status);
    return status;
  }

  // Map VSync Interrupt
  status = pdev_get_interrupt(&pdev_, IRQ_VSYNC, 0, vsync_irq_.reset_and_get_address());
  if (status != ZX_OK) {
    DISP_ERROR("Could not map vsync interrupt\n");
    return status;
  }

  // Map VD1_WR Interrupt (used for capture)
  status = pdev_get_interrupt(&pdev_, IRQ_VD1_WR, 0, vd1_wr_irq_.reset_and_get_address());
  if (status != ZX_OK) {
    DISP_ERROR("Could not map vd1 wr interrupt\n");
    return status;
  }

  auto start_thread = [](void* arg) { return static_cast<AstroDisplay*>(arg)->VSyncThread(); };
  status = thrd_create_with_name(&vsync_thread_, start_thread, this, "vsync_thread");
  if (status != ZX_OK) {
    DISP_ERROR("Could not create vsync_thread\n");
    return status;
  }

  auto vd_thread = [](void* arg) { return static_cast<AstroDisplay*>(arg)->CaptureThread(); };
  status = thrd_create_with_name(&capture_thread_, vd_thread, this, "capture_thread");
  if (status != ZX_OK) {
    DISP_ERROR("Could not create capture_thread\n");
    return status;
  }

  auto cleanup = fbl::MakeAutoCall([&]() { DdkRelease(); });

  status = DdkAdd("astro-display");
  if (status != ZX_OK) {
    DISP_ERROR("Could not add device\n");
    return status;
  }

  cleanup.cancel();
  return ZX_OK;
}