TEST(AtlHenTests, RequireThat_Cluck_IsCalledOnAsyncCluckObserver_WhenPassedToHen)
{
    auto observer = make_self<IAsyncCluckObserverMock>();
    EXPECT_CALL(*observer, OnCluck()).WillOnce(Return(S_OK));

    CComPtr<IHen> hen;
    HR(CoCreateInstance(CLSID_AtlHen, nullptr, CLSCTX_INPROC_SERVER, IID_IHen, reinterpret_cast<void**>(&hen)));

    HR(hen->CluckAsync(observer));
}