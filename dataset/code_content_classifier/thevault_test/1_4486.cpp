void CMpegAudEnc::LoadOutputCapabilities(DWORD sample_rate)
{
    m_CapsNum = 0;

    // Clear out any existing output capabilities
    ZeroMemory(OutputCaps, sizeof(OutputCaps));

    // Create the set of Constant Bit Rate output capabilities that are
    // supported for the current input pin sampling rate.
    for (int i = 0;  i < NUMELMS(OutputCapabilities); i++) {
        if (0 == sample_rate % OutputCapabilities[i].nSampleRate) {

            // Add this output capability to the OutputCaps list
            OutputCaps[m_CapsNum] = OutputCapabilities[i];
            m_CapsNum++;

            // Don't overrun the hard-coded capabilities array limit
            if (m_CapsNum > (int)MAX_IAMSTREAMCONFIG_CAPS) break;
        }
    }
}