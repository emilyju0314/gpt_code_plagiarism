void muracAA::onBrArch(const int &value) {
    cout << "@" << sc_time_stamp() << " onBrArch" << endl;

    int ret = -1;
    int fd;
    unsigned long int pc = 0;
    unsigned int instruction_size = 0;
    unsigned long int ptr = 0;
    unsigned char* fmap;
    char *tmp_file_name = strdup("/tmp/murac_AA_XXXXXX");

    if (busRead(MURAC_PC_ADDRESS, (unsigned char*) &pc, 4) < 0) {
      cout << "@" << sc_time_stamp() << " Memory read error !" << endl;
      goto trigger_return_interrupt;
    }

    cout << "@" << sc_time_stamp() << " PC: 0x" << hex << pc << endl;

    if (busRead(MURAC_PC_ADDRESS + 4, (unsigned char*) &instruction_size, 4) < 0) {
      cout << "@" << sc_time_stamp() << " Memory read error !" << endl;
      goto trigger_return_interrupt;
    }
    cout << "@" << sc_time_stamp() << " Instruction size: " << dec << instruction_size << endl;

    if (busRead(MURAC_PC_ADDRESS + 8, (unsigned char*) &ptr, 4) < 0) {
      cout << "@" << sc_time_stamp() << " Memory read error !" << endl;
      goto trigger_return_interrupt;
    }
    cout << "@" << sc_time_stamp() << " Ptr : " << hex << ptr << dec << endl;

    cout << "@" << sc_time_stamp() << " Reading embedded AA simulation file " << endl;

    fd = mkostemp (tmp_file_name, O_RDWR | O_CREAT | O_TRUNC);
    if (fd == -1) {
      cout << "Error: Cannot open temporary file for writing." << endl;
      goto trigger_return_interrupt;
    }
    ret = lseek(fd, instruction_size-1, SEEK_SET);
    if (ret == -1) {
      close(fd);
      cout << "Error: Cannot call lseek() on temporary file." << endl;
      goto trigger_return_interrupt;
    }
    ret = ::write(fd, "", 1);
    if (ret != 1) {
      close(fd);
      cout << "Error: Error writing last byte of the temporary file." << endl;
      goto trigger_return_interrupt;
    }

    fmap = (unsigned char*) mmap(0, instruction_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (fmap == MAP_FAILED) {
      close(fd);
      cout << "Error: Error mmapping the temporary file." << endl;
      goto trigger_return_interrupt;
    }

    // Write the file
    if (busRead(pc, fmap, instruction_size) < 0) {
      cout << "@" << sc_time_stamp() << " Memory read error !" << endl;
      munmap(fmap, instruction_size);
      close(fd);
      goto trigger_return_interrupt;
    }

    if (munmap(fmap, instruction_size) == -1) {
      close(fd);
      cout << "Error: Error un-mmapping the temporary file." << endl;
      goto trigger_return_interrupt;
    }

    close(fd);

    cout << "@" << sc_time_stamp() << " Running murac AA simulation " << endl;
    ret = invokePluginSimulation(tmp_file_name, ptr);
    cout << "@" << sc_time_stamp() << " Simulation result = " << ret << endl;

    remove(tmp_file_name);
    
  trigger_return_interrupt:

    free(tmp_file_name);

    cout << "@" << sc_time_stamp() << " Returning to PA " << endl;

    // Trigger interrupt for return to PA
    intRetArch.write(1);
    intRetArch.write(0);
}