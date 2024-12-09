TEST(AtlHenTests, RequireThat_Cluck_IsCalledOnAsyncCluckObserver_WhenPassedToHenThatLivesInSeparateProcess)
{
    auto observer = make_self<IAsyncCluckObserverMock>();
    EXPECT_CALL(*observer, OnCluck()).WillOnce(Return(S_OK));

    // Create the hen on a separate process running through dllhost. You can find the dllhost instance
    // in task manager by looking for the 860d9d2c-315d-4e01-93b6-ded0e8d133c3 in the command line
    // This is the AppId registered in the AtlHenModule.cpp
    CComPtr<IHen> hen;
    HR(CoCreateInstance(CLSID_AtlHen, nullptr, CLSCTX_LOCAL_SERVER, IID_IHen, reinterpret_cast<void**>(&hen)));

    HR(hen->CluckAsync(observer));
}