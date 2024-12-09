TEST_F(WalletClientTest, GetWalletItems) {
  delegate_.ExpectLogWalletApiCallDuration(AutofillMetrics::GET_WALLET_ITEMS,
                                           1);
  delegate_.ExpectBaselineMetrics();

  wallet_client_->GetWalletItems(base::string16(), base::string16());

  VerifyAndFinishRequest(net::HTTP_OK,
                         kGetWalletItemsValidRequest,
                         kGetWalletItemsValidResponse);
  EXPECT_EQ(1U, delegate_.wallet_items_received());
}