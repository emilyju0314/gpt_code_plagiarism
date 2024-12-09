static zx_status_t append_reserved_mem(ACPI_TABLE_DMAR* table, zx_iommu_desc_intel_t* desc,
                                       size_t desc_len, size_t* bytes_needed) {
  const uintptr_t records_start = (uintptr_t)table + sizeof(*table);
  const uintptr_t records_end = (uintptr_t)table + table->Header.Length;

  zx_iommu_desc_intel_scope_t* desc_scopes =
      (zx_iommu_desc_intel_scope_t*)((uintptr_t)desc + sizeof(*desc));
  const size_t num_desc_scopes = desc->scope_bytes / sizeof(zx_iommu_desc_intel_scope_t);

  uintptr_t next_reserved_mem_desc_base = (uintptr_t)desc + sizeof(zx_iommu_desc_intel_t) +
                                          desc->scope_bytes + desc->reserved_memory_bytes;

  *bytes_needed = 0;
  for (uintptr_t addr = records_start; addr < records_end;) {
    ACPI_DMAR_HEADER* record_hdr = (ACPI_DMAR_HEADER*)addr;
    switch (record_hdr->Type) {
      case ACPI_DMAR_TYPE_RESERVED_MEMORY: {
        ACPI_DMAR_RESERVED_MEMORY* rec = (ACPI_DMAR_RESERVED_MEMORY*)record_hdr;

        if (desc->pci_segment != rec->Segment) {
          break;
        }

        zx_iommu_desc_intel_reserved_memory_t* mem_desc =
            (zx_iommu_desc_intel_reserved_memory_t*)next_reserved_mem_desc_base;
        size_t mem_desc_size = sizeof(*mem_desc);

        // Search for scopes that match
        for (uintptr_t scope = addr + 24; scope < addr + rec->Header.Length;) {
          ACPI_DMAR_DEVICE_SCOPE* s = (ACPI_DMAR_DEVICE_SCOPE*)scope;
          // TODO(teisenbe): We should skip scope types we don't
          // care about here

          // Search for a scope in the descriptor that matches this
          // ACPI scope.
          bool no_matches = true;
          for (size_t i = 0; i < num_desc_scopes; ++i) {
            zx_iommu_desc_intel_scope_t* scope_desc = &desc_scopes[i];
            const bool scope_matches = scope_eq(scope_desc, s);

            no_matches &= !scope_matches;

            // If this is a whole segment descriptor, then a match
            // corresponds to an entry we should ignore.
            if (scope_matches && !desc->whole_segment) {
              zx_iommu_desc_intel_scope_t* new_scope_desc =
                  (zx_iommu_desc_intel_scope_t*)(next_reserved_mem_desc_base + mem_desc_size);
              mem_desc_size += sizeof(zx_iommu_desc_intel_scope_t);

              if (next_reserved_mem_desc_base + mem_desc_size <= (uintptr_t)desc + desc_len) {
                memcpy(new_scope_desc, scope_desc, sizeof(*scope_desc));
              }
              break;
            }
          }

          if (no_matches && desc->whole_segment) {
            zx_iommu_desc_intel_scope_t other_scope;
            zx_status_t status = acpi_scope_to_desc(s, &other_scope);
            if (status != ZX_ERR_WRONG_TYPE && status != ZX_OK) {
              return status;
            }
            if (status == ZX_OK) {
              zx_iommu_desc_intel_scope_t* new_scope_desc =
                  (zx_iommu_desc_intel_scope_t*)(next_reserved_mem_desc_base + mem_desc_size);
              mem_desc_size += sizeof(zx_iommu_desc_intel_scope_t);

              if (next_reserved_mem_desc_base + mem_desc_size <= (uintptr_t)desc + desc_len) {
                memcpy(new_scope_desc, &other_scope, sizeof(other_scope));
              }
            }
          }

          scope += s->Length;
        }

        // If this descriptor does not have any scopes, ignore it
        if (mem_desc_size == sizeof(*mem_desc)) {
          break;
        }

        if (next_reserved_mem_desc_base + mem_desc_size <= (uintptr_t)desc + desc_len) {
          mem_desc->base_addr = rec->BaseAddress;
          mem_desc->len = rec->EndAddress - rec->BaseAddress + 1;
          mem_desc->scope_bytes = static_cast<uint8_t>(mem_desc_size - sizeof(*mem_desc));
          next_reserved_mem_desc_base += mem_desc_size;
        }
        *bytes_needed += mem_desc_size;

        break;
      }
    }

    addr += record_hdr->Length;
  }

  // Check if we weren't able to write all of the entries above.
  if (*bytes_needed + sizeof(zx_iommu_desc_intel_t) + desc->scope_bytes +
          desc->reserved_memory_bytes >
      desc_len) {
    return ZX_ERR_BUFFER_TOO_SMALL;
  }

  return ZX_OK;
}