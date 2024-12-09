Reshape::Reshape()
{
  m_fwdLUT = nullptr;
  m_invLUT = nullptr;
  m_chromaScale = 1 << CSCALE_FP_PREC;
  m_vpduX = -1;
  m_vpduY = -1;
}