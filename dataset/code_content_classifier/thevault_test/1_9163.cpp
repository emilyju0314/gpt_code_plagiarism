TEST(ScaleTest, DecodeOptionalSuccess) {
  // clang-format off
    auto bytes = ByteArray{
            0,              // first value
            1, 1,           // second value
            1, 255,         // third value
            0,              // fourth value
            1, 255, 1,      // fifth value
            1, 1, 2, 3, 4}; // sixth value
  // clang-format on

  auto stream = ScaleDecoderStream{bytes};

  // decode nullopt uint8_t
  {
    boost::optional<uint8_t> opt;
    ASSERT_NO_THROW((stream >> opt));
    ASSERT_FALSE(opt.has_value());
  }

  // decode optional uint8_t
  {
    boost::optional<uint8_t> opt;
    ASSERT_NO_THROW((stream >> opt));
    ASSERT_TRUE(opt.has_value());
    ASSERT_EQ(*opt, 1);
  }

  // decode optional negative int8_t
  {
    boost::optional<int8_t> opt;
    ASSERT_NO_THROW((stream >> opt));
    ASSERT_TRUE(opt.has_value());
    ASSERT_EQ(*opt, -1);
  }

  // decode nullopt uint16_t
  // it requires 1 zero byte just like any other nullopt
  {
    boost::optional<uint16_t> opt;
    ASSERT_NO_THROW((stream >> opt));
    ASSERT_FALSE(opt.has_value());
  }

  // decode optional uint16_t
  {
    boost::optional<uint16_t> opt;
    ASSERT_NO_THROW((stream >> opt));
    ASSERT_TRUE(opt.has_value());
    ASSERT_EQ(*opt, 511);
  }

  // decode optional uint32_t
  {
    boost::optional<uint32_t> opt;
    ASSERT_NO_THROW((stream >> opt));
    ASSERT_TRUE(opt.has_value());
    ASSERT_EQ(*opt, 67305985);
  }
}