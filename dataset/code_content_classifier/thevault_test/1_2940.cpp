void DigitalIn::Refresh() {
    if (*m_changeRegPtr & m_inputDataMask) {
        m_filterTicksLeft = m_filterLength;

        if (!m_filterLength) {
            // If the filter length is zero, set the filtered state
            UpdateFilterState();
        }
    }
    else if (m_filterTicksLeft && !--m_filterTicksLeft) {
        // When we decrement to zero, set the filtered state
        UpdateFilterState();
    }
}