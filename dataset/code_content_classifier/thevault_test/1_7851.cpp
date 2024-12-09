LoopFilter::LoopFilter()
{
  xPelFilterLuma  = xPelFilterLumaCore;
  xFilteringPandQ = xFilteringPandQCore;

#if defined( TARGET_SIMD_X86 ) && ENABLE_SIMD_DBLF
  initLoopFilterX86();
#endif
}