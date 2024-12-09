double SRSTime::chip_time_ns(uint16_t bc, uint16_t tdc, float offset, float slope) const {
  return static_cast<double>(bc) * static_cast<double>(bc_factor_) +
      (static_cast<double>(bc_factor_) - static_cast<double>(tdc) * tdc_factor_ -
          static_cast<double>(offset)) * static_cast<double>(slope);
}