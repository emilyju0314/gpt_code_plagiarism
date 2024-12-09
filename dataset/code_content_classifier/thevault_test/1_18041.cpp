BOOST_AUTO_TEST_CASE(coins_cache_simulation_test)
{
    // Various coverage trackers.
    bool removed_all_caches = false;
    bool reached_4_caches = false;
    bool added_an_entry = false;
    bool added_an_unspendable_entry = false;
    bool removed_an_entry = false;
    bool updated_an_entry = false;
    bool found_an_entry = false;
    bool missed_an_entry = false;
    bool uncached_an_entry = false;

    // A simple map to track what we expect the cache stack to represent.
    std::map<COutPoint, Coin> result;

    // The cache stack.
    CCoinsViewTest base; // A CCoinsViewTest at the bottom.
    std::vector<CCoinsViewCacheTest*> stack; // A stack of CCoinsViewCaches on top.
    stack.push_back(new CCoinsViewCacheTest(&base)); // Start with one cache.

    // Use a limited set of random transaction ids, so we do test overwriting entries.
    std::vector<uint256> txids;
    txids.resize(NUM_SIMULATION_ITERATIONS / 8);
    for (unsigned int i = 0; i < txids.size(); i++) {
        txids[i] = InsecureRand256();
    }

    for (unsigned int i = 0; i < NUM_SIMULATION_ITERATIONS; i++) {
        // Do a random modification.
        {
            uint256 txid = txids[InsecureRandRange(txids.size())]; // txid we're going to modify in this iteration.
            Coin& coin = result[COutPoint(txid, 0)];

            // Determine whether to test HaveCoin before or after Access* (or both). As these functions
            // can influence each other's behaviour by pulling things into the cache, all combinations
            // are tested.
            bool test_havecoin_before = InsecureRandBits(2) == 0;
            bool test_havecoin_after = InsecureRandBits(2) == 0;

            bool result_havecoin = test_havecoin_before ? stack.back()->HaveCoin(COutPoint(txid, 0)) : false;
            const Coin& entry = (InsecureRandRange(500) == 0) ? AccessByTxid(*stack.back(), txid) : stack.back()->AccessCoin(COutPoint(txid, 0));
            BOOST_CHECK(coin == entry);
            BOOST_CHECK(!test_havecoin_before || result_havecoin == !entry.IsSpent());

            if (test_havecoin_after) {
                bool ret = stack.back()->HaveCoin(COutPoint(txid, 0));
                BOOST_CHECK(ret == !entry.IsSpent());
            }

            if (InsecureRandRange(5) == 0 || coin.IsSpent()) {
                Coin newcoin;
                newcoin.out.nValue = InsecureRand32();
                newcoin.nHeight = 1;
                if (InsecureRandRange(16) == 0 && coin.IsSpent()) {
                    newcoin.out.scriptPubKey.assign(1 + InsecureRandBits(6), OP_RETURN);
                    BOOST_CHECK(newcoin.out.scriptPubKey.IsUnspendable());
                    added_an_unspendable_entry = true;
                } else {
                    newcoin.out.scriptPubKey.assign(InsecureRandBits(6), 0); // Random sizes so we can test memory usage accounting
                    (coin.IsSpent() ? added_an_entry : updated_an_entry) = true;
                    coin = newcoin;
                }
                stack.back()->AddCoin(COutPoint(txid, 0), std::move(newcoin), !coin.IsSpent() || InsecureRand32() & 1);
            } else {
                removed_an_entry = true;
                coin.Clear();
                BOOST_CHECK(stack.back()->SpendCoin(COutPoint(txid, 0)));
            }
        }

        // One every 10 iterations, remove a random entry from the cache
        if (InsecureRandRange(10) == 0) {
            COutPoint out(txids[InsecureRand32() % txids.size()], 0);
            int cacheid = InsecureRand32() % stack.size();
            stack[cacheid]->Uncache(out);
            uncached_an_entry |= !stack[cacheid]->HaveCoinInCache(out);
        }

        // Once every 1000 iterations and at the end, verify the full cache.
        if (InsecureRandRange(1000) == 1 || i == NUM_SIMULATION_ITERATIONS - 1) {
            for (const auto& entry : result) {
                bool have = stack.back()->HaveCoin(entry.first);
                const Coin& coin = stack.back()->AccessCoin(entry.first);
                BOOST_CHECK(have == !coin.IsSpent());
                BOOST_CHECK(coin == entry.second);
                if (coin.IsSpent()) {
                    missed_an_entry = true;
                } else {
                    BOOST_CHECK(stack.back()->HaveCoinInCache(entry.first));
                    found_an_entry = true;
                }
            }
            for (const CCoinsViewCacheTest *test : stack) {
                test->SelfTest();
            }
        }

        if (InsecureRandRange(100) == 0) {
            // Every 100 iterations, flush an intermediate cache
            if (stack.size() > 1 && InsecureRandBool() == 0) {
                unsigned int flushIndex = InsecureRandRange(stack.size() - 1);
                BOOST_CHECK(stack[flushIndex]->Flush());
            }
        }
        if (InsecureRandRange(100) == 0) {
            // Every 100 iterations, change the cache stack.
            if (stack.size() > 0 && InsecureRandBool() == 0) {
                //Remove the top cache
                BOOST_CHECK(stack.back()->Flush());
                delete stack.back();
                stack.pop_back();
            }
            if (stack.size() == 0 || (stack.size() < 4 && InsecureRandBool())) {
                //Add a new cache
                CCoinsView* tip = &base;
                if (stack.size() > 0) {
                    tip = stack.back();
                } else {
                    removed_all_caches = true;
                }
                stack.push_back(new CCoinsViewCacheTest(tip));
                if (stack.size() == 4) {
                    reached_4_caches = true;
                }
            }
        }
    }

    // Clean up the stack.
    while (stack.size() > 0) {
        delete stack.back();
        stack.pop_back();
    }

    // Verify coverage.
    BOOST_CHECK(removed_all_caches);
    BOOST_CHECK(reached_4_caches);
    BOOST_CHECK(added_an_entry);
    BOOST_CHECK(added_an_unspendable_entry);
    BOOST_CHECK(removed_an_entry);
    BOOST_CHECK(updated_an_entry);
    BOOST_CHECK(found_an_entry);
    BOOST_CHECK(missed_an_entry);
    BOOST_CHECK(uncached_an_entry);
}