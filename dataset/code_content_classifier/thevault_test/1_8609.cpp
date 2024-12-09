TEST_F(FlatBuffersTest, BasicTest1) {
    flatbuffers::FlatBufferBuilder builder(1024);

    auto name = builder.CreateString("wow");

    auto node = CreateFlatNode(builder, -1, name, OpType_TRANSFORM_SAME, transform::Ones, {0});

    builder.Finish(node);

    // now we have our buffer with data
    uint8_t *buf = builder.GetBufferPointer();
    int size = builder.GetSize();
    ASSERT_TRUE(size > 0);



    auto restored = GetFlatNode(buf);

    auto gA = new Node(restored);
    auto gB = new Node(restored);

    ASSERT_TRUE(gA->equals(gB));

    delete gA;
    delete gB;
}