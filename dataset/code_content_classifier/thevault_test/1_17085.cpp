TEST(WebSocketErrorToNetErrorTest, ResultsAreCorrect) {
  EXPECT_THAT(WebSocketErrorToNetError(kWebSocketNormalClosure), IsOk());
  EXPECT_EQ(ERR_WS_PROTOCOL_ERROR,
            WebSocketErrorToNetError(kWebSocketErrorProtocolError));
  EXPECT_EQ(ERR_MSG_TOO_BIG,
            WebSocketErrorToNetError(kWebSocketErrorMessageTooBig));
  EXPECT_EQ(ERR_CONNECTION_CLOSED,
            WebSocketErrorToNetError(kWebSocketErrorNoStatusReceived));
  EXPECT_EQ(ERR_SSL_PROTOCOL_ERROR,
            WebSocketErrorToNetError(kWebSocketErrorTlsHandshake));
}