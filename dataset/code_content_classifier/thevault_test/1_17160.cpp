TEST_F(FtpCtrlResponseBufferTest, NoNesting) {
  EXPECT_THAT(PushDataToBuffer("230-FirstLine\r\n"), IsOk());
  EXPECT_FALSE(buffer_.ResponseAvailable());

  EXPECT_THAT(PushDataToBuffer("300-Continuation\r\n"), IsOk());
  EXPECT_FALSE(buffer_.ResponseAvailable());

  EXPECT_THAT(PushDataToBuffer("300 Still continuation\r\n"), IsOk());
  EXPECT_FALSE(buffer_.ResponseAvailable());

  EXPECT_THAT(PushDataToBuffer("230 Real End\r\n"), IsOk());
  ASSERT_TRUE(buffer_.ResponseAvailable());

  FtpCtrlResponse response = buffer_.PopResponse();
  EXPECT_FALSE(buffer_.ResponseAvailable());
  EXPECT_EQ(230, response.status_code);
  ASSERT_EQ(2U, response.lines.size());
  EXPECT_EQ("FirstLine300-Continuation300 Still continuation",
            response.lines[0]);
  EXPECT_EQ("Real End", response.lines[1]);
}