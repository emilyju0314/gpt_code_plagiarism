TEST_F(DuplicateATVfixture,
       DISABLED_DuplicateATV_DifferentContaining_BA_removeB) {
  auto p2 = payloads;
  ASSERT_TRUE(AddPayloads(chain[99].getHash(), p2));
  ASSERT_TRUE(alttree.setState(chain[99].getHash(), state));
  auto p2id = payloads.atvs.at(0).getId();

  auto p1 = payloads;
  // remove context blocks
  p1.context.clear();
  ASSERT_FALSE(AddPayloads(chain[100].getHash(), p1));

  auto index99 = alttree.getBlockIndex(chain[99].getHash());
  auto& atvids = index99->getPayloadIds<ATV>();
  ASSERT_EQ(atvids.size(), 1);
  ASSERT_EQ(*atvids.begin(), p2.atvs.at(0).getId());
  ASSERT_TRUE(index99->isValid());
  auto index100 = alttree.getBlockIndex(chain[100].getHash());
  ASSERT_TRUE(index100->isValid());
  auto& atvids2 = index100->getPayloadIds<ATV>();
  ASSERT_EQ(atvids2.size(), 0);

  // we should be able to switch to 99
  ASSERT_TRUE(alttree.setState(chain[99].getHash(), state));
  // and to to 100
  ASSERT_TRUE(alttree.setState(chain[100].getHash(), state));
  auto& atvids3 = index99->getPayloadIds<ATV>();
  ASSERT_EQ(atvids3.size(), 1);
  ASSERT_EQ(*atvids3.begin(), p2id);
  ASSERT_TRUE(index99->isValid());
  ASSERT_TRUE(index100->isValid());
  auto& atvids4 = index100->getPayloadIds<ATV>();
  ASSERT_EQ(atvids4.size(), 0);
  ASSERT_EQ(alttree.vbk().getBestChain().tip()->getHeight(), 11);
  ASSERT_EQ(alttree.btc().getBestChain().tip()->getHeight(), 10);

  // now we remove that duplicating payloads
  // remain vbk blocks as a payloads in the alt block [99]
  p2.context.clear();
  ASSERT_TRUE(alttree.setState(chain[98].getHash(), state));
  ASSERT_NO_FATAL_FAILURE(alttree.removePayloads(chain[99].getHash()));
  ASSERT_TRUE(alttree.setState(chain[100].getHash(), state));
  // both indices are valid
  ASSERT_TRUE(index99->isValid());
  ASSERT_TRUE(index100->isValid());
  {
    auto& _atvids = index100->getPayloadIds<ATV>();
    ASSERT_EQ(_atvids.size(), 0);
  }
}