static bool AddNmfToRequest(std::string prog, struct PP_Var req_var) {
  if (UseBuiltInFallback(&prog, req_var)) {
    return true;
  }
  if (access(prog.c_str(), R_OK) != 0) {
    errno = ENOENT;
    return false;
  }

  if (!ExpandShBang(&prog, req_var)) {
    return false;
  }

  // Check fallback again in case of #! expanded to something else.
  if (UseBuiltInFallback(&prog, req_var)) {
    return true;
  }

  // Check for pnacl.
  if (IsPNaClType(prog)) {
    AddNmfToRequestForPNaCl(prog, req_var);
    return true;
  }

  std::string arch;
  std::vector<std::string> dependencies;
  if (!nspawn_find_arch_and_library_deps(prog, &arch, &dependencies))
    return false;

  if (!dependencies.empty()) {
    AddNmfToRequestForShared(prog, arch, dependencies, req_var);
  } else  {
    // No dependencies means the main binary is statically linked.
    AddNmfToRequestForStatic(prog, arch, req_var);
  }

  return true;
}