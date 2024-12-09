void DigitalIn::UpdateFilterState() {
    m_stateFiltered = !(*m_inRegPtr & m_inputDataMask);
    ShiftReg.ShifterState(m_stateFiltered, m_ledMask);

    // Update the SysManager Register
    if (m_stateFiltered) {
        atomic_or_fetch(m_inputRegRTPtr, 1UL << m_clearCorePin);
    }
    else {
        atomic_and_fetch(m_inputRegRTPtr, ~(1UL << m_clearCorePin));
    }
}