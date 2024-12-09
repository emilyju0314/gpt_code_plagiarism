void mustSucceed(Result result, const Twine &errorMessage) {
  if (result == Result::Success)
    return;

  if (errorMessage.isTriviallyEmpty())
    LLPC_ERRS("Unhandled error result\n");
  else
    LLPC_ERRS("Unhandled error result: " << errorMessage << "\n");

  assert(false && "Result is not Success");
}