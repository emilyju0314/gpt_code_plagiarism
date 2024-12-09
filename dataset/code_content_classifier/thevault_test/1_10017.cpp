static void addCommonFrontendArgs(const ToolChain &TC,
                                  const OutputInfo &OI,
                                  const CommandOutput &output,
                                  const ArgList &inputArgs,
                                  ArgStringList &arguments) {
  const llvm::Triple &Triple = TC.getTriple();

  // Only pass -target to the REPL or immediate modes if it was explicitly
  // specified on the command line.
  switch (OI.CompilerMode) {
  case OutputInfo::Mode::REPL:
  case OutputInfo::Mode::Immediate:
    if (!inputArgs.hasArg(options::OPT_target))
      break;
    LLVM_FALLTHROUGH;
  case OutputInfo::Mode::StandardCompile:
  case OutputInfo::Mode::SingleCompile:
    arguments.push_back("-target");
    arguments.push_back(inputArgs.MakeArgString(Triple.str()));
    break;
  }

  // Enable address top-byte ignored in the ARM64 backend.
  if (Triple.getArch() == llvm::Triple::aarch64) {
    arguments.push_back("-Xllvm");
    arguments.push_back("-aarch64-use-tbi");
  }

  // Enable or disable ObjC interop appropriately for the platform
  if (Triple.isOSDarwin()) {
    arguments.push_back("-enable-objc-interop");
  } else {
    arguments.push_back("-disable-objc-interop");
  }

  // Handle the CPU and its preferences.
  inputArgs.AddLastArg(arguments, options::OPT_target_cpu);

  if (!OI.SDKPath.empty()) {
    arguments.push_back("-sdk");
    arguments.push_back(inputArgs.MakeArgString(OI.SDKPath));
  }

  inputArgs.AddAllArgs(arguments, options::OPT_I);
  inputArgs.AddAllArgs(arguments, options::OPT_F, options::OPT_Fsystem);

  inputArgs.AddLastArg(arguments, options::OPT_AssertConfig);
  inputArgs.AddLastArg(arguments, options::OPT_autolink_force_load);
  inputArgs.AddLastArg(arguments, options::OPT_color_diagnostics);
  inputArgs.AddLastArg(arguments, options::OPT_fixit_all);
  inputArgs.AddLastArg(arguments,
                       options::OPT_warn_swift3_objc_inference_minimal,
                       options::OPT_warn_swift3_objc_inference_complete);
  inputArgs.AddLastArg(arguments, options::OPT_typo_correction_limit);
  inputArgs.AddLastArg(arguments, options::OPT_enable_app_extension);
  inputArgs.AddLastArg(arguments, options::OPT_enable_testing);
  inputArgs.AddLastArg(arguments, options::OPT_g_Group);
  inputArgs.AddLastArg(arguments, options::OPT_import_underlying_module);
  inputArgs.AddLastArg(arguments, options::OPT_module_cache_path);
  inputArgs.AddLastArg(arguments, options::OPT_module_link_name);
  inputArgs.AddLastArg(arguments, options::OPT_nostdimport);
  inputArgs.AddLastArg(arguments, options::OPT_parse_stdlib);
  inputArgs.AddLastArg(arguments, options::OPT_resource_dir);
  inputArgs.AddLastArg(arguments, options::OPT_solver_memory_threshold);
  inputArgs.AddLastArg(arguments, options::OPT_value_recursion_threshold);
  inputArgs.AddLastArg(arguments, options::OPT_warn_swift3_objc_inference);
  inputArgs.AddLastArg(arguments, options::OPT_Rpass_EQ);
  inputArgs.AddLastArg(arguments, options::OPT_Rpass_missed_EQ);
  inputArgs.AddLastArg(arguments, options::OPT_suppress_warnings);
  inputArgs.AddLastArg(arguments, options::OPT_profile_generate);
  inputArgs.AddLastArg(arguments, options::OPT_profile_use);
  inputArgs.AddLastArg(arguments, options::OPT_profile_coverage_mapping);
  inputArgs.AddLastArg(arguments, options::OPT_warnings_as_errors);
  inputArgs.AddLastArg(arguments, options::OPT_sanitize_EQ);
  inputArgs.AddLastArg(arguments, options::OPT_sanitize_coverage_EQ);
  inputArgs.AddLastArg(arguments, options::OPT_swift_version);
  inputArgs.AddLastArg(arguments, options::OPT_enforce_exclusivity_EQ);
  inputArgs.AddLastArg(arguments, options::OPT_stats_output_dir);
  inputArgs.AddLastArg(arguments, options::OPT_trace_stats_events);
  inputArgs.AddLastArg(arguments,
                       options::OPT_solver_shrink_unsolved_threshold);
  inputArgs.AddLastArg(arguments, options::OPT_O_Group);
  inputArgs.AddLastArg(arguments, options::OPT_RemoveRuntimeAsserts);
  inputArgs.AddLastArg(arguments, options::OPT_AssumeSingleThreaded);

  // Pass on any build config options
  inputArgs.AddAllArgs(arguments, options::OPT_D);

  // Pass through the values passed to -Xfrontend.
  inputArgs.AddAllArgValues(arguments, options::OPT_Xfrontend);

  // Pass through any subsystem flags.
  inputArgs.AddAllArgs(arguments, options::OPT_Xllvm);
  inputArgs.AddAllArgs(arguments, options::OPT_Xcc);

  const std::string &moduleDocOutputPath =
      output.getAdditionalOutputForType(types::TY_SwiftModuleDocFile);
  if (!moduleDocOutputPath.empty()) {
    arguments.push_back("-emit-module-doc-path");
    arguments.push_back(moduleDocOutputPath.c_str());
  }

  if (llvm::sys::Process::StandardErrHasColors())
    arguments.push_back("-color-diagnostics");

  const std::string &SerializedDiagnosticsPath =
    output.getAdditionalOutputForType(types::TY_SerializedDiagnostics);
  if (!SerializedDiagnosticsPath.empty()) {
    arguments.push_back("-serialize-diagnostics-path");
    arguments.push_back(SerializedDiagnosticsPath.c_str());
  }
}