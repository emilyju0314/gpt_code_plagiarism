void RestoreRegistersOrDie(RegisterState& register_state) {
  auto result = register_state.RestoreRegisters();
  FAIL_IF(result.has_error(), "Unable to restore register state in tracee: \"%s\"",
          result.error().message());
}