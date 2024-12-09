STDMETHODIMP CSwapAPOMFX::LockForProcess(UINT32 u32NumInputConnections,
    APO_CONNECTION_DESCRIPTOR** ppInputConnections,  
    UINT32 u32NumOutputConnections, APO_CONNECTION_DESCRIPTOR** ppOutputConnections)
{
    ASSERT_NONREALTIME();
    HRESULT hr = S_OK;

    if (m_queueId != 0)
    {
        hr = SwapMFXApoAsyncCallback::Create(&m_asyncCallback, m_queueId);
        IF_FAILED_JUMP(hr, Exit);

        wil::com_ptr_nothrow<IRtwqAsyncResult> asyncResult;
        hr = RtwqCreateAsyncResult(static_cast<IAudioProcessingObject*>(this), m_asyncCallback.get(), nullptr, &asyncResult);
        IF_FAILED_JUMP(hr, Exit);

        hr = RtwqPutWorkItem(m_queueId, 0, asyncResult.get());
        IF_FAILED_JUMP(hr, Exit);
    }

    hr = CBaseAudioProcessingObject::LockForProcess(u32NumInputConnections,
        ppInputConnections, u32NumOutputConnections, ppOutputConnections);
    IF_FAILED_JUMP(hr, Exit);
    
Exit:
    return hr;
}