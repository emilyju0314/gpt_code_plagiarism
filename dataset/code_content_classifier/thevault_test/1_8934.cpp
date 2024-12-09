constexpr void
    load_elf_file(loader::ext_elf_file_t &mut_file, phdr_table_t const &phdr_table) noexcept
    {
        mut_file.e_type = bfelf::ET_EXEC.get();
        *mut_file.e_ident.at_if(bfelf::EI_MAG0) = bfelf::ELFMAG0.get();
        *mut_file.e_ident.at_if(bfelf::EI_MAG1) = bfelf::ELFMAG1.get();
        *mut_file.e_ident.at_if(bfelf::EI_MAG2) = bfelf::ELFMAG2.get();
        *mut_file.e_ident.at_if(bfelf::EI_MAG3) = bfelf::ELFMAG3.get();
        *mut_file.e_ident.at_if(bfelf::EI_CLASS) = bfelf::ELFCLASS64.get();
        *mut_file.e_ident.at_if(bfelf::EI_OSABI) = bfelf::ELFOSABI_SYSV.get();

        mut_file.e_phdr = phdr_table.data();
        mut_file.e_phnum = bsl::to_u16(phdr_table.size()).get();

        mut_file.e_entry = HYPERVISOR_PAGE_SIZE.get();
    }