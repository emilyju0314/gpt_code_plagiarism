TEST_F(TxTest, UnmapCmdQueue) {
  ASSERT_OK(iwl_pcie_tx_init(trans_));
  trans_ops_.write32 = FakeEchoWrite32;

  struct iwl_host_cmd hcmd = {
      .flags = CMD_WANT_SKB,
      .id = ECHO_CMD,
  };
  hcmd.len[0] = 0;
  hcmd.data[0] = NULL;

  struct iwl_trans_pcie* trans_pcie = IWL_TRANS_GET_PCIE_TRANS(trans_);
  int txq_id = trans_pcie->cmd_queue;
  struct iwl_txq* txq = trans_pcie->txq[txq_id];

  // Adds first half of commands.
  int half = (txq->n_window + 1) / 2;
  for (int i = 0; i < half; ++i) {
    ASSERT_OK(iwl_trans_pcie_send_hcmd(trans_, &hcmd));
    EXPECT_TRUE(trans_pcie->ref_cmd_in_flight);
  }
  iwl_pcie_txq_unmap(trans_, trans_pcie->cmd_queue);
  EXPECT_FALSE(trans_pcie->ref_cmd_in_flight);

  // Adds another half and plus one to ensure wrapping.
  for (int i = 0; i < half + 1; ++i) {
    ASSERT_OK(iwl_trans_pcie_send_hcmd(trans_, &hcmd));
    EXPECT_TRUE(trans_pcie->ref_cmd_in_flight);
  }
  iwl_pcie_txq_unmap(trans_, trans_pcie->cmd_queue);
  EXPECT_FALSE(trans_pcie->ref_cmd_in_flight);

  // All num_tbs should have been cleared to zero.
  for (int index = 0; index < txq->n_window; ++index) {
    void* tfd = iwl_pcie_get_tfd(trans_, txq, index);
    if (trans_->cfg->use_tfh) {
      struct iwl_tfh_tfd* tfd_fh = static_cast<struct iwl_tfh_tfd*>(tfd);
      EXPECT_EQ(0, tfd_fh->num_tbs);
    } else {
      struct iwl_tfd* tfd_fh = static_cast<struct iwl_tfd*>(tfd);
      EXPECT_EQ(0, tfd_fh->num_tbs);
    }
  }
}