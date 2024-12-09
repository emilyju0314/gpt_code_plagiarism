void CompleteDisassemble(const Err& err, MemoryDump dump, fxl::WeakPtr<Process> weak_process,
                         const FormatAsmOpts& options) {
  Console* console = Console::get();
  if (err.has_error()) {
    console->Output(err);
    return;
  }

  if (!weak_process)
    return;  // Give up if the process went away.

  OutputBuffer out;
  Err format_err =
      FormatAsmContext(weak_process->session()->arch_info(), dump, options, weak_process.get(),
                       SourceFileProviderImpl(weak_process->GetTarget()->settings()), &out);
  if (format_err.has_error()) {
    console->Output(err);
    return;
  }

  console->Output(out);
}