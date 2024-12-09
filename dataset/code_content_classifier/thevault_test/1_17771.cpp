TEST(OnlineFileSource, TEST_REQUIRES_SERVER(NetworkStatusChangePreempt)) {
    util::RunLoop loop;
    std::unique_ptr<FileSource> fs = std::make_unique<OnlineFileSource>(ResourceOptions::Default());
    fs->pause();

    const auto start = Clock::now();
    int counter = 0;

    const Resource resource{ Resource::Unknown, "http://127.0.0.1:3001/test" };
    std::unique_ptr<AsyncRequest> req = fs->request(resource, [&](Response res) {
        const auto duration = std::chrono::duration<const double>(Clock::now() - start).count();
        if (counter == 0) {
            EXPECT_GT(0.2, duration) << "Response came in too late";
        } else if (counter == 1) {
            EXPECT_LT(0.39, duration) << "Preempted retry triggered too early";
            EXPECT_GT(0.6, duration) << "Preempted retry triggered too late";
        } else if (counter > 1) {
            FAIL() << "Retried too often";
        }
        ASSERT_NE(nullptr, res.error);
        EXPECT_EQ(Response::Error::Reason::Connection, res.error->reason);
        ASSERT_FALSE(res.data.get());
        EXPECT_FALSE(bool(res.expires));
        EXPECT_FALSE(res.mustRevalidate);
        EXPECT_FALSE(bool(res.modified));
        EXPECT_FALSE(bool(res.etag));

        if (counter++ == 1) {
            req.reset();
            loop.stop();
        }
    });

    // After 400 milliseconds, we're going to trigger a NetworkStatus change.
    util::Timer reachableTimer;
    reachableTimer.start(Milliseconds(400), Duration::zero(), [] () {
        mbgl::NetworkStatus::Reachable();
    });

    fs->resume();
    loop.run();
}