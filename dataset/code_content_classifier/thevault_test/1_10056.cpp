TEST(Win32SocketServerTest, TestPump) {
  Win32SocketServer server(NULL);
  SocketServerScope scope(&server);
  EXPECT_EQ(TRUE, PostMessage(NULL, WM_USER, 999, 0));
  server.Pump();
  MSG msg;
  EXPECT_EQ(TRUE, PeekMessage(&msg, NULL, WM_USER, 0, PM_REMOVE));
  EXPECT_EQ(WM_USER, msg.message);
  EXPECT_EQ(999, msg.wParam);
}