TEST_F(DeclarableOpsTests4, Test_Split_2) {
    auto x = NDArrayFactory::create<double>('c', {5, 12});
    auto axis = NDArrayFactory::create<double>('c', {1, 1}, {1.f});

    std::vector<Nd4jLong> list0 = {0,0, 0,3};
    std::vector<Nd4jLong> list1 = {0,0, 3,6};
    std::vector<Nd4jLong> list2 = {0,0, 6,9};
    std::vector<Nd4jLong> list3 = {0,0, 9,12};

    auto sub0 = x(list0, true);
    auto sub1 = x(list1, true);
    auto sub2 = x(list2, true);
    auto sub3 = x(list3, true);

    sub0.assign(0.0f);
    sub1.assign(1.0f);
    sub2.assign(2.0f);
    sub3.assign(3.0f);


    sd::ops::split op;
    auto result = op.evaluate({&axis, &x}, {}, {4});
    ASSERT_EQ(ND4J_STATUS_OK, result.status());

    auto z0 = result.at(0);
    auto z1 = result.at(1);
    auto z2 = result.at(2);
    auto z3 = result.at(3);

    ASSERT_TRUE(sub0.isSameShape(z0));
    ASSERT_TRUE(sub1.isSameShape(z1));
    ASSERT_TRUE(sub2.isSameShape(z2));
    ASSERT_TRUE(sub3.isSameShape(z3));

    ASSERT_TRUE(sub0.equalsTo(z0));
    ASSERT_TRUE(sub1.equalsTo(z1));
    ASSERT_TRUE(sub2.equalsTo(z2));
    ASSERT_TRUE(sub3.equalsTo(z3));


}