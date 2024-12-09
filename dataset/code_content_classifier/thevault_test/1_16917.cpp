TEST_F(DuplicateATVfixture,
       DISABLED_DuplicateATV_DifferentContaining_BA_removeA) {
  auto p1 = payloads;
  ASSERT_TRUE(AddPayloads(chain[100].getHash(), p1));
  auto p1id = payloads.atvs[0].getId();

  auto p2 = payloads;
  ASSERT_TRUE(AddPayloads(chain[99].getHash(), p2));
  auto p2id = payloads.atvs[0].getId();

  auto index99 = alttree.getBlockIndex(chain[99].getHash());
  auto& atvids = index99->getPayloadIds<ATV>();
  ASSERT_EQ(atvids.size(), 1);
  ASSERT_EQ(*atvids.begin(), p2id);
  ASSERT_TRUE(index99->isValid());
  auto index100 = alttree.getBlockIndex(chain[100].getHash());
  ASSERT_TRUE(index100->isValid());
  auto& atvids2 = index100->getPayloadIds<ATV>();
  ASSERT_EQ(atvids2.size(), 1);
  ASSERT_EQ(*atvids2.begin(), p1id);

  // we should be able to switch to 99
  ASSERT_TRUE(alttree.setState(chain[99].getHash(), state));
  // but not to 100, because 100 duplicates 99
  ASSERT_FALSE(alttree.setState(chain[100].getHash(), state));
  ASSERT_EQ(state.GetPath(), "ALT-bad-command+ALT-duplicate");
  auto& atvids3 = index99->getPayloadIds<ATV>();
  ASSERT_EQ(atvids3.size(), 1);
  ASSERT_EQ(*atvids3.begin(), p2id);

  ASSERT_TRUE(index99->isValid());
  ASSERT_FALSE(index100->isValid());
  auto& atvids4 = index100->getPayloadIds<ATV>();
  ASSERT_EQ(atvids4.size(), 1);
  ASSERT_EQ(*atvids4.begin(), p1id);

  // now we remove that duplicating payloads
  ASSERT_NO_FATAL_FAILURE(alttree.removePayloads(chain[100].getHash()));
  // index100 is now valid
  ASSERT_TRUE(index100->isValid());
  auto& atvids5 = index100->getPayloadIds<ATV>();
  // chain100 contains 0 command groups
  ASSERT_EQ(atvids5.size(), 0);
  // we can switch back to chain 100
  ASSERT_TRUE(alttree.setState(chain[100].getHash(), state));
}