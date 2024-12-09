TEST(ConnectionPoolASIO, TestHostTimeoutRace) {
    auto fixture = unittest::getFixtureConnectionString();

    NetworkInterfaceASIO::Options options;
    options.streamFactory = stdx::make_unique<AsyncStreamFactory>();
    options.connectionPoolOptions.hostTimeout = Milliseconds(1);
    options.timerFactory = stdx::make_unique<AsyncTimerFactoryASIO>();
    NetworkInterfaceASIO net{std::move(options)};

    net.startup();
    auto guard = MakeGuard([&] { net.shutdown(); });

    for (int i = 0; i < 1000; i++) {
        Deferred<StatusWith<RemoteCommandResponse>> deferred;
        net.startCommand(
            makeCallbackHandle(),
            RemoteCommandRequest{fixture.getServers()[0], "admin", BSON("ping" << 1), BSONObj()},
            [&](StatusWith<RemoteCommandResponse> resp) { deferred.emplace(std::move(resp)); });

        ASSERT_OK(deferred.get().getStatus());
        sleepmillis(1);
    }
}