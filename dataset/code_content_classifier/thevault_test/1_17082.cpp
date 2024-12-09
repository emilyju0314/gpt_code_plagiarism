TEST(ECTest, DISABLED_ScalarBaseMultVectorsTwoPoint) {
  bssl::UniquePtr<BN_CTX> ctx(BN_CTX_new());
  ASSERT_TRUE(ctx);

  FileTestGTest("crypto/fipsmodule/ec/ec_scalar_base_mult_tests.txt",
                [&](FileTest *t) {
    bssl::UniquePtr<EC_GROUP> group = GetCurve(t, "Curve");
    ASSERT_TRUE(group);
    bssl::UniquePtr<BIGNUM> n = GetBIGNUM(t, "N");
    ASSERT_TRUE(n);
    bssl::UniquePtr<BIGNUM> x = GetBIGNUM(t, "X");
    ASSERT_TRUE(x);
    bssl::UniquePtr<BIGNUM> y = GetBIGNUM(t, "Y");
    ASSERT_TRUE(y);
    bool is_infinity = BN_is_zero(x.get()) && BN_is_zero(y.get());

    bssl::UniquePtr<BIGNUM> px(BN_new());
    ASSERT_TRUE(px);
    bssl::UniquePtr<BIGNUM> py(BN_new());
    ASSERT_TRUE(py);
    auto check_point = [&](const EC_POINT *p) {
      if (is_infinity) {
        EXPECT_TRUE(EC_POINT_is_at_infinity(group.get(), p));
      } else {
        ASSERT_TRUE(EC_POINT_get_affine_coordinates_GFp(
            group.get(), p, px.get(), py.get(), ctx.get()));
        EXPECT_EQ(0, BN_cmp(x.get(), px.get()));
        EXPECT_EQ(0, BN_cmp(y.get(), py.get()));
      }
    };

    const EC_POINT *g = EC_GROUP_get0_generator(group.get());
    bssl::UniquePtr<EC_POINT> p(EC_POINT_new(group.get()));
    ASSERT_TRUE(p);
    bssl::UniquePtr<BIGNUM> a(BN_new()), b(BN_new());
    for (int i = -64; i < 64; i++) {
      SCOPED_TRACE(i);
      ASSERT_TRUE(BN_set_word(a.get(), abs(i)));
      if (i < 0) {
        ASSERT_TRUE(BN_sub(a.get(), EC_GROUP_get0_order(group.get()), a.get()));
      }

      ASSERT_TRUE(BN_copy(b.get(), n.get()));
      ASSERT_TRUE(BN_sub(b.get(), b.get(), a.get()));
      if (BN_is_negative(b.get())) {
        ASSERT_TRUE(BN_add(b.get(), b.get(), EC_GROUP_get0_order(group.get())));
      }

      ASSERT_TRUE(
          EC_POINT_mul(group.get(), p.get(), a.get(), g, b.get(), ctx.get()));
      check_point(p.get());

      EC_SCALAR a_scalar, b_scalar;
      ASSERT_TRUE(ec_bignum_to_scalar(group.get(), &a_scalar, a.get()));
      ASSERT_TRUE(ec_bignum_to_scalar(group.get(), &b_scalar, b.get()));
      ASSERT_TRUE(ec_point_mul_scalar_public(group.get(), &p->raw, &a_scalar,
                                             &g->raw, &b_scalar));
      check_point(p.get());
    }
  });
}