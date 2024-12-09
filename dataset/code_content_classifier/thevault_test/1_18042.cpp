BOOST_AUTO_TEST_CASE(SelectCoins_test)
{
    testWallet.SetupLegacyScriptPubKeyMan();

    // Random generator stuff
    std::default_random_engine generator;
    std::exponential_distribution<double> distribution (100);
    FastRandomContext rand;

    // Run this test 100 times
    for (int i = 0; i < 100; ++i)
    {
        empty_wallet();

        // Make a wallet with 1000 exponentially distributed random inputs
        for (int j = 0; j < 1000; ++j)
        {
            add_coin((CAmount)(distribution(generator)*10000000));
        }

        // Generate a random fee rate in the range of 100 - 400
        CFeeRate rate(rand.randrange(300) + 100);

        // Generate a random target value between 1000 and wallet balance
        CAmount target = rand.randrange(balance - 1000) + 1000;

        // Perform selection
        CoinSelectionParams coin_selection_params_knapsack(false, 34, 148, CFeeRate(0), 0);
        CoinSelectionParams coin_selection_params_bnb(true, 34, 148, CFeeRate(0), 0);
        CoinSet out_set;
        CAmount out_value = 0;
        bool bnb_used = false;
        BOOST_CHECK(testWallet.SelectCoinsMinConf(target, filter_standard, GroupCoins(vCoins), out_set, out_value, coin_selection_params_bnb, bnb_used) ||
                    testWallet.SelectCoinsMinConf(target, filter_standard, GroupCoins(vCoins), out_set, out_value, coin_selection_params_knapsack, bnb_used));
        BOOST_CHECK_GE(out_value, target);
    }
}