void ConfigBuilderBase::SetPseudoRegister(
    uint32_t reg,     // Register number
    uint32_t value)   // Value to set
{
    LLPC_ASSERT(GeneratingMsgPack() == false);
    m_pseudoRegisters.push_back(reg);
    m_pseudoRegisters.push_back(value);
}