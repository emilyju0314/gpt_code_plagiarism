static zx_status_t append_scopes(ACPI_DMAR_HARDWARE_UNIT* unit, size_t max_scopes,
                                 zx_iommu_desc_intel_scope_t* scopes, size_t* num_scopes_found) {
  size_t num_scopes = 0;
  uintptr_t scope;
  const uintptr_t addr = (uintptr_t)unit;
  for (scope = addr + 16; scope < addr + unit->Header.Length;) {
    ACPI_DMAR_DEVICE_SCOPE* s = (ACPI_DMAR_DEVICE_SCOPE*)scope;
    zxlogf(DEBUG1, "  DMAR Scope: %u, bus %u\n", s->EntryType, s->Bus);
    for (size_t i = 0; i < (s->Length - sizeof(*s)) / 2; ++i) {
      uint16_t v = *(uint16_t*)(scope + sizeof(*s) + 2 * i);
      zxlogf(DEBUG1, "    Path %ld: %02x.%02x\n", i, v & 0xffu, (uint16_t)(v >> 8));
    }
    scope += s->Length;

    // Count the scopes we care about
    switch (s->EntryType) {
      case ACPI_DMAR_SCOPE_TYPE_ENDPOINT:
      case ACPI_DMAR_SCOPE_TYPE_BRIDGE:
        num_scopes++;
        break;
    }
  }

  if (num_scopes_found) {
    *num_scopes_found = num_scopes;
  }
  if (!scopes) {
    return ZX_OK;
  }

  if (num_scopes > max_scopes) {
    return ZX_ERR_BUFFER_TOO_SMALL;
  }

  size_t cur_num_scopes = 0;
  for (scope = addr + 16; scope < addr + unit->Header.Length && cur_num_scopes < max_scopes;) {
    ACPI_DMAR_DEVICE_SCOPE* s = (ACPI_DMAR_DEVICE_SCOPE*)scope;

    zx_status_t status = acpi_scope_to_desc(s, &scopes[cur_num_scopes]);
    if (status != ZX_OK && status != ZX_ERR_WRONG_TYPE) {
      return status;
    }
    if (status == ZX_OK) {
      cur_num_scopes++;
    }

    scope += s->Length;
  }

  // Since |num_scopes| is the number of ENDPOINT and BRIDGE entries, and
  // |acpi_scope_to_desc| doesn't return ZX_ERR_WRONG_TYPE for those types of
  // entries, we should always have seen that number of entries when we reach
  // here.
  assert(cur_num_scopes == num_scopes);
  return ZX_OK;
}