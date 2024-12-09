TEST_F(ViewManagerTest, TwoClientsGetDifferentConnectionIds) {
  ASSERT_NO_FATAL_FAILURE(EstablishSecondConnection(true));
  EXPECT_EQ("OnEmbed creator=mojo:test_url",
            ChangesToDescription1(connection2_->changes())[0]);

  // It isn't strictly necessary that the second connection gets 2, but these
  // tests are written assuming that is the case. The key thing is the
  // connection ids of |connection_| and |connection2_| differ.
  EXPECT_EQ(2, connection2_->changes()[0].connection_id);
}