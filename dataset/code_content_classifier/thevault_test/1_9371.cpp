HRESULT
CHalfApp::ReleaseSineToneDataBuffer
(
    void
)
{
    m_pbSineToneDataBuffer = nullptr;
    m_dwSineToneDataBufferSize = 0;
    m_dwSineToneDataBufferPosition = 0;

    return S_OK;
}