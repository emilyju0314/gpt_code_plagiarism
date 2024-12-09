TEST_F(InstrumentFunctionTest, CheckIntParameters) {
  function_name_ = "CheckIntParameters";
  pid_ = fork();
  CHECK(pid_ != -1);
  if (pid_ == 0) {
    prctl(PR_SET_PDEATHSIG, SIGTERM);

    [[maybe_unused]] volatile uint64_t sum = 0;
    while (true) {
      sum += CheckIntParameters(0, 0, 0, 0, 0, 0, 0, 0);
      // Endless loops without side effects are UB and recent versions of clang optimize
      // it away.
    }
  }
  PrepareInstrumentation("EntryPayloadClobberParameterRegisters", kExitPayloadFunctionName);
  ErrorMessageOr<uint64_t> address_after_prologue_or_error = CreateTrampoline(
      pid_, function_address_, function_code_, trampoline_address_, entry_payload_function_address_,
      return_trampoline_address_, capstone_handle_, relocation_map_);
  EXPECT_THAT(address_after_prologue_or_error, HasNoError());
  ErrorMessageOr<void> result =
      InstrumentFunction(pid_, function_address_, /*function_id=*/42,
                         address_after_prologue_or_error.value(), trampoline_address_);
  EXPECT_THAT(result, HasNoError());
  RestartAndRemoveInstrumentation();
}