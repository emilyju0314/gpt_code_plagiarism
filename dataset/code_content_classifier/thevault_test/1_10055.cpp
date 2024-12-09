TEST(Win32SocketServerTest, TestWait) {
  Win32SocketServer server(NULL);
  uint32_t start = Time();
  server.Wait(1000, true);
  EXPECT_GE(TimeSince(start), 1000);
}