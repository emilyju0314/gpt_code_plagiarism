TEST(AtlHenTests, RequireThat_CluckAsync_ReturnsSuccess_WhenCalledWithValidCluckObserver) {
    CComPtr<IHen> hen;
    HR(CoCreateInstance(CLSID_AtlHen, nullptr, CLSCTX_INPROC_SERVER, IID_IHen, reinterpret_cast<void**>(&hen)));

    CComPtr<IAsyncCluckObserver> cluckObserver;
    HR(CoCreateInstance(CLSID_AtlCluckObserver, nullptr, CLSCTX_INPROC_SERVER, IID_IAsyncCluckObserver, reinterpret_cast<void**>(&cluckObserver)));

    EXPECT_HRESULT_SUCCEEDED(hen->CluckAsync(cluckObserver));
}