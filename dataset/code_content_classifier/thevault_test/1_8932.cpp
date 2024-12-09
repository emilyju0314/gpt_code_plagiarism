constexpr void
    load_phdr_table(phdr_table_t &mut_phdr_table, elf_file_buf_t const &elf_file_buf) noexcept
    {
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_type = bfelf::PT_LOAD.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_flags = (bfelf::PF_X | bfelf::PF_R).get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_offset = elf_file_buf.data();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_vaddr = PT_LOAD_RE_VADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_paddr = PT_LOAD_RE_PADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_filesz = PT_LOAD_RE_FILSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_memsz = PT_LOAD_RE_MEMSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RE_IDX)->p_align = HYPERVISOR_PAGE_SIZE.get();

        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_type = bfelf::PT_LOAD.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_flags = bfelf::PF_R.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_offset = elf_file_buf.data();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_vaddr = PT_LOAD_RO_VADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_paddr = PT_LOAD_RO_PADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_filesz = PT_LOAD_RO_FILSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_memsz = PT_LOAD_RO_MEMSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RO_IDX)->p_align = HYPERVISOR_PAGE_SIZE.get();

        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_type = bfelf::PT_LOAD.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_flags = (bfelf::PF_W | bfelf::PF_R).get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_offset = elf_file_buf.data();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_vaddr = PT_LOAD_RW_VADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_paddr = PT_LOAD_RW_PADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_filesz = PT_LOAD_RW_FILSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_memsz = PT_LOAD_RW_MEMSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_RW_IDX)->p_align = HYPERVISOR_PAGE_SIZE.get();

        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_type = bfelf::PT_LOAD.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_flags = (bfelf::PF_W | bfelf::PF_R).get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_offset = elf_file_buf.data();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_vaddr = PT_LOAD_TLS_VADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_paddr = PT_LOAD_TLS_PADDR.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_filesz = PT_LOAD_TLS_FILSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_memsz = PT_LOAD_TLS_MEMSZ.get();
        mut_phdr_table.at_if(PHDR_PT_LOAD_TLS_IDX)->p_align = HYPERVISOR_PAGE_SIZE.get();

        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_type = bfelf::PT_TLS.get();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_flags = (bfelf::PF_W | bfelf::PF_R).get();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_offset = elf_file_buf.data();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_vaddr = PT_TLS_VADDR.get();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_paddr = PT_TLS_PADDR.get();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_filesz = PT_TLS_FILSZ.get();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_memsz = PT_TLS_MEMSZ.get();
        mut_phdr_table.at_if(PHDR_PT_TLS_IDX)->p_align = {};

        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_type = bfelf::PT_GNU_STACK.get();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_flags = (bfelf::PF_W | bfelf::PF_R).get();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_offset = elf_file_buf.data();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_vaddr = PT_GNU_STACK_VADDR.get();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_paddr = PT_GNU_STACK_PADDR.get();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_filesz = PT_GNU_STACK_FILSZ.get();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_memsz = PT_GNU_STACK_MEMSZ.get();
        mut_phdr_table.at_if(PHDR_PT_GNU_STACK_IDX)->p_align = {};
    }