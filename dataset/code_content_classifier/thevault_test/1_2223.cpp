std::optional<std::string> DemangleForSymInfo(const ParsedIdentifier& identifier) {
  std::string full_input = identifier.GetFullNameNoQual();
  if (full_input.empty() || full_input[0] != '_') {
    // Filter out all names that don't start with underscores. sym-info is mostly used to look up
    // functions and variables. Functions should be demangled, but variables shouldn't. The problem
    // is that some common variables like "f" and "i" demangle to "float" and "int" respectively
    // which is not what the user wants. By only unmangling when things start with an underscore,
    // we mostly restrict to mangled function names.
    return std::nullopt;
  }

  std::optional<std::string> result;

  // TODO(brettw) use "demangled = llvm::demangle() when we roll LLVM. It avoids the buffer
  // allocation problem.
  int demangle_status = llvm::demangle_unknown_error;
  char* demangled_buf =
      llvm::itaniumDemangle(full_input.c_str(), nullptr, nullptr, &demangle_status);
  if (demangle_status == llvm::demangle_success && full_input != demangled_buf)
    result.emplace(demangled_buf);
  if (demangled_buf)
    free(demangled_buf);

  return result;
}