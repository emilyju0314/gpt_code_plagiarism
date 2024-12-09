bool VmoFromBytes(const uint8_t* bytes, size_t num_bytes, uint32_t type, uint32_t version,
                  fsl::SizedVmo* sized_vmo_ptr) {
  FXL_CHECK(sized_vmo_ptr);

  zx::vmo vmo;
  size_t total_size = num_bytes + sizeof(type) + sizeof(version);
  zx_status_t status = zx::vmo::create(total_size, 0u, &vmo);
  if (status < 0) {
    FXL_PLOG(WARNING, status) << "zx::vmo::create failed";
    return false;
  }

  if (num_bytes > 0) {
    status = vmo.write(&type, 0, sizeof(uint32_t));
    if (status < 0) {
      FXL_PLOG(WARNING, status) << "zx::vmo::write snapshot type failed";
      return false;
    }
    status = vmo.write(&version, sizeof(uint32_t), sizeof(uint32_t));
    if (status < 0) {
      FXL_PLOG(WARNING, status) << "zx::vmo::write snapshot version failed";
      return false;
    }
    status = vmo.write(bytes, 2 * sizeof(uint32_t), num_bytes);
    if (status < 0) {
      FXL_PLOG(WARNING, status) << "zx::vmo::write bytes failed";
      return false;
    }
  }

  *sized_vmo_ptr = fsl::SizedVmo(std::move(vmo), total_size);

  return true;
}