Result reportError(Error &&err) {
  // For details on llvm error handling, see https://llvm.org/docs/ProgrammersManual.html#recoverable-errors.
  assert(err && "llvm::ErrorSuccess is not an error");

  Result result = Result::ErrorUnknown;
  handleAllErrors(
      std::move(err),
      [&result](const ResultError &resultError) {
        result = resultError.getResult();
        LLPC_ERRS(resultError.message() << "\n");
      },
      [](const ErrorInfoBase &baseError) { LLPC_ERRS(baseError.message() << "\n"); });
  return result;
}