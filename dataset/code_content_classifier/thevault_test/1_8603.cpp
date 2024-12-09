TEST_F(DeclarableOpsTests4, Test_Split_3) {
    auto x = NDArrayFactory::create<double>('c', {6, 12});
    auto axis = NDArrayFactory::create<double>('c', {1, 1}, {0.f});

    std::vector<Nd4jLong> list0 = {0,2, 0,0};
    std::vector<Nd4jLong> list1 = {2,4, 0,0};
    std::vector<Nd4jLong> list2 = {4,6, 0,0};

    auto sub0 = x(list0, true);
    auto sub1 = x(list1, true);
    auto sub2 = x(list2, true);

    sub0.assign(0.0f);
    sub1.assign(1.0f);
    sub2.assign(2.0f);

    sd::ops::split op;
    auto result = op.evaluate({&axis, &x}, {}, {3});
    ASSERT_EQ(ND4J_STATUS_OK, result.status());

    auto z0 = result.at(0);
    auto z1 = result.at(1);
    auto z2 = result.at(2);

    ASSERT_TRUE(sub0.isSameShape(z0));
    ASSERT_TRUE(sub1.isSameShape(z1));
    ASSERT_TRUE(sub2.isSameShape(z2));

    ASSERT_TRUE(sub0.equalsTo(z0));
    ASSERT_TRUE(sub1.equalsTo(z1));
    ASSERT_TRUE(sub2.equalsTo(z2));
}