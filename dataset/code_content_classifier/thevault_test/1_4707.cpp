void Elf::InitGnuDebugdata() {
  if (!valid_ || interface_->gnu_debugdata_offset() == 0) {
    return;
  }

  gnu_debugdata_memory_ = interface_->CreateGnuDebugdataMemory();
  gnu_debugdata_interface_.reset(CreateInterfaceFromMemory(gnu_debugdata_memory_.get()));
  ElfInterface* gnu = gnu_debugdata_interface_.get();
  if (gnu == nullptr) {
    return;
  }

  // Ignore the load_bias from the compressed section, the correct load bias
  // is in the uncompressed data.
  int64_t load_bias;
  if (gnu->Init(&load_bias)) {
    gnu->InitHeaders();
    interface_->SetGnuDebugdataInterface(gnu);
  } else {
    // Free all of the memory associated with the gnu_debugdata section.
    gnu_debugdata_memory_.reset(nullptr);
    gnu_debugdata_interface_.reset(nullptr);
  }
}