trace::X86TraceGenerator::~X86TraceGenerator()
{
  report("destructor");
  dump_opcode_stats();
  finalize();

  if (init) {
#if WRITE_DEBUG == 1
    debug_stream->close();
    delete debug_stream;
#endif
    txt_kernel_config_file.close();
  }

//  delete[] opcode_stats;
}