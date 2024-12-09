TEST_P(ECCurveTest, P224Bug) {
  // P = -G
  const EC_POINT *g = EC_GROUP_get0_generator(group());
  bssl::UniquePtr<EC_POINT> p(EC_POINT_dup(g, group()));
  ASSERT_TRUE(p);
  ASSERT_TRUE(EC_POINT_invert(group(), p.get(), nullptr));

  // Compute 31 * P + 32 * G = G
  bssl::UniquePtr<EC_POINT> ret(EC_POINT_new(group()));
  ASSERT_TRUE(ret);
  bssl::UniquePtr<BIGNUM> bn31(BN_new()), bn32(BN_new());
  ASSERT_TRUE(bn31);
  ASSERT_TRUE(bn32);
  ASSERT_TRUE(BN_set_word(bn31.get(), 31));
  ASSERT_TRUE(BN_set_word(bn32.get(), 32));
  ASSERT_TRUE(EC_POINT_mul(group(), ret.get(), bn32.get(), p.get(), bn31.get(),
                           nullptr));
  EXPECT_EQ(0, EC_POINT_cmp(group(), ret.get(), g, nullptr));

  // Repeat the computation with |ec_point_mul_scalar_public|, which ties the
  // additions together.
  EC_SCALAR sc31, sc32;
  ASSERT_TRUE(ec_bignum_to_scalar(group(), &sc31, bn31.get()));
  ASSERT_TRUE(ec_bignum_to_scalar(group(), &sc32, bn32.get()));
  ASSERT_TRUE(
      ec_point_mul_scalar_public(group(), &ret->raw, &sc32, &p->raw, &sc31));
  EXPECT_EQ(0, EC_POINT_cmp(group(), ret.get(), g, nullptr));
}