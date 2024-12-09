TEST(WebSocketHandshakeChallengeTest, RFC6455) {
  const std::string key = "dGhlIHNhbXBsZSBub25jZQ==";
  std::string accept = ComputeSecWebSocketAccept(key);
  EXPECT_EQ("s3pPLMBiTxaQ9kYGzzhZRbK+xOo=", accept);
}