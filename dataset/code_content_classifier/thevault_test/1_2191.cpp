zx_status_t AmlClock::ClkMeasureUtil(uint32_t clk, uint64_t* clk_freq) {
  if (!msr_mmio_) {
    return ZX_ERR_NOT_SUPPORTED;
  }

  // Set the measurement gate to 64uS.
  uint32_t value = 64 - 1;
  msr_mmio_->Write32(value, clk_msr_offsets_.reg0_offset);
  // Disable continuous measurement.
  // Disable interrupts.
  value = MSR_CONT | MSR_INTR;
  // Clear the clock source.
  value |= MSR_CLK_SRC_MASK << MSR_CLK_SRC_SHIFT;
  msr_mmio_->ClearBits32(value, clk_msr_offsets_.reg0_offset);

  value = ((clk << MSR_CLK_SRC_SHIFT) |  // Select the MUX.
           MSR_RUN |                     // Enable the clock.
           MSR_ENABLE);                  // Enable measuring.
  msr_mmio_->SetBits32(value, clk_msr_offsets_.reg0_offset);

  // Wait for the measurement to be done.
  for (uint32_t i = 0; i < MSR_WAIT_BUSY_RETRIES; i++) {
    value = msr_mmio_->Read32(clk_msr_offsets_.reg0_offset);
    if (value & MSR_BUSY) {
      // Wait a little bit before trying again.
      zx_nanosleep(zx_deadline_after(ZX_USEC(MSR_WAIT_BUSY_TIMEOUT_US)));
      continue;
    } else {
      // Disable measuring.
      msr_mmio_->ClearBits32(MSR_ENABLE, clk_msr_offsets_.reg0_offset);
      // Get the clock value.
      value = msr_mmio_->Read32(clk_msr_offsets_.reg2_offset);
      // Magic numbers, since lack of documentation.
      *clk_freq = (((value + 31) & MSR_VAL_MASK) / 64);
      return ZX_OK;
    }
  }
  return ZX_ERR_TIMED_OUT;
}