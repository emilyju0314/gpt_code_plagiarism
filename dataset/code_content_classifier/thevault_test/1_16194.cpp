TEST_F(GraftWalletTest, UseForkRule)
{
    GraftWallet2 *wallet = new GraftWallet2(true);
    ASSERT_NO_THROW(wallet->load_graft(wallet_account1, "", ""));
    // connect to daemon and get the blocks
    wallet->init(DAEMON_ADDR);
    ASSERT_TRUE(wallet->use_fork_rules(2, 0));
    ASSERT_TRUE(wallet->use_fork_rules(4, 0));
    ASSERT_TRUE(wallet->use_fork_rules(5, 0));
    ASSERT_TRUE(wallet->use_fork_rules(6, 0));
    // this will fail on rta testnet as we need to update block version there
    ASSERT_TRUE(wallet->use_fork_rules(7, 0));
    ASSERT_FALSE(wallet->use_fork_rules(8, 0));
    ASSERT_TRUE(wallet->use_fork_rules(2, 10));
    ASSERT_TRUE(wallet->use_fork_rules(4, 10));
    ASSERT_TRUE(wallet->use_fork_rules(5, 10));
    ASSERT_TRUE(wallet->use_fork_rules(6, 10));
    // this will fail on rta testnet as we need to update block version there
    ASSERT_TRUE(wallet->use_fork_rules(7, 10));
    ASSERT_FALSE(wallet->use_fork_rules(8, 10));
}