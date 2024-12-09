TEST(AtlHenTests, RequireThat_CoCreateInstance_CreatesCluckObserver_WhenCalledWithCluckObserversClassId)
{
    CComPtr<IAsyncCluckObserver> observer;
    HR(CoCreateInstance(CLSID_AtlCluckObserver, nullptr, CLSCTX_INPROC_SERVER, IID_IAsyncCluckObserver, reinterpret_cast<void**>(&observer)));
    EXPECT_NE(observer, nullptr);
}