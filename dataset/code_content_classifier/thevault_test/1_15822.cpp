TEST(AtlHenTests, RequireThat_Cluck_IsExecutedOnMainThread_WhenCalledFromWorkerThread)
{
    const auto mainThreadId = GetCurrentThreadId();

    // Configure the async cluck observer to fail unless it is called on the main thread
    // After all, it was created on a single threaded apartment (STA), and it should not be
    // allowed to call it from any other thread.
    auto observer = make_self<IAsyncCluckObserverMock>();
    EXPECT_CALL(*observer, OnCluck()).WillOnce(Invoke([mainThreadId]
        {
            EXPECT_EQ(GetCurrentThreadId(), mainThreadId);
            return S_OK; // Feel free to put a breakpoint here, and see which thread we are called on
        }));

    CComPtr<IHen> hen;
    HR(CoCreateInstance(CLSID_AtlHen, nullptr, CLSCTX_INPROC_SERVER, IID_IHen, reinterpret_cast<void**>(&hen)));

    // To play nice with COM, we should not pass COM interface pointers to other threads
    // unless they are 'agile'. We can do this with a simple wrapper that converts the interfaces
    // to agile interfaces. We could also marshal the interface to a stream using CoMarshalInterThreadInterfaceInStream
    // and CoGetInterfaceAndReleaseStream.
    const auto agileHen = AgilePtr<IHen>(hen);
    const auto agileObserver = AgilePtr<IAsyncCluckObserver>(observer);

    std::thread thread{ [agileHen, agileObserver, mainThreadId]
    {
        ComRuntime runtime{Apartment::MultiThreaded};

        SetThreadDescription(GetCurrentThread(), L"Worker thread"); // Help debugging
        HR(agileHen.Get()->CluckAsync(agileObserver.Get()));

        // Notify main thread that it can now exit its message loop
        PostThreadMessage(mainThreadId, WM_QUIT, 0, 0);
    } };

    // Pump messages from COM runtime to allow function calls from worker thread to
    // main thread to be processed. This is how COM allows communication between threads.
    MSG message{};
    while (const auto result = GetMessage(&message, 0, 0, 0))
    {
        if (-1 != result)
            DispatchMessage(&message);
    }

    thread.join();
}