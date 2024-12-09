HRESULT
CHalfApp::CreateSineToneDataBuffer
(
    WAVEFORMATEX* pWfx
)
{
    HRESULT hr = S_OK;

    if (!VERIFY_IS_NOT_NULL(pWfx)) {
        hr = E_FAIL;
        return hr;
    }

    m_dwSineToneDataBufferSize = (DWORD)(((ULONGLONG)BUF_LEN_IN_MS * pWfx->nSamplesPerSec / 1000) * pWfx->nBlockAlign);
    m_pbSineToneDataBuffer.reset((BYTE*)LocalAlloc(LPTR, m_dwSineToneDataBufferSize));
    if (!VERIFY_IS_NOT_NULL(m_pbSineToneDataBuffer)) {
        hr = E_OUTOFMEMORY;
        return hr;
    }

    if (m_DataFlow == render) // Sine tone for render
    {
        if (!VERIFY_SUCCEEDED(hr = FillBufferWithSineSignal(
            g_pBasicLog, XFAIL,
            pWfx,
            TEST_AMPLITUDE, // amplitude
            TEST_FREQUENCY, // frequency
            0.0, // initial phase,
            0.0, // dc
            Method_NoDithering,
            m_pbSineToneDataBuffer.get(),
            m_dwSineToneDataBufferSize / pWfx->nBlockAlign,
            m_dwSineToneDataBufferSize
        ))) {
            return hr;
        }

        m_dwSineToneDataBufferPosition = 0;
    }
    else // Silence for capture
    {
        memset(m_pbSineToneDataBuffer.get(), 0, m_dwSineToneDataBufferSize);
        m_dwSineToneDataBufferPosition = 0;
    }

    return hr;
}