trace::X86TraceGenerator::X86TraceGenerator()
  : init(false)
  , num_warps_per_block(0)
  , num_total_warps(0)
  , total_inst_count(0)
  , blockDimX(1)
  , blockDimY(1)
  , blockDimZ(1)
  , gridDimX(1)
  , gridDimY(1)
  , gridDimZ(1)
  , kernel_count(0)
{
  m_compute = "2.0";
#ifndef USE_32BIT_ADDR
  mem_addr_flag = ~0llu;
#else
  mem_addr_flag = ~0u;
#endif

//  opcode_stats = new uint64_t[GPU_OPCODE_LAST];
}