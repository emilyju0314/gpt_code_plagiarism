TYPED_TEST(LazyDeserialization, DeserializeLazyStructWithoutIndex) {
  using Struct = typename TypeParam::Struct;
  using LazyStruct = typename TypeParam::LazyStruct;

  Struct foo;
  foo.field1_ref().emplace();
  foo.field2_ref().emplace();
  foo.field3_ref().emplace();
  foo.field4_ref().emplace();

  // We need first deserialization since even though `this->genLazyStruct()`
  // returns lazy struct, all lazy fields are already deserialized.
  LazyStruct lazyFoo;
  this->deserialize(this->serialize(this->genLazyStruct()), lazyFoo);
  this->deserialize(this->serialize(foo), lazyFoo);

  if (std::is_same_v<Struct, TerseFoo>) {
    // If struct enabled terse writes, we won't serialize fields that has
    // default value, thus we won't change lazyFoo after deserialization
    EXPECT_EQ(lazyFoo, this->genLazyStruct());
  } else {
    EXPECT_TRUE(lazyFoo.field1_ref()->empty());
    EXPECT_TRUE(lazyFoo.field2_ref()->empty());
    EXPECT_TRUE(lazyFoo.field3_ref()->empty());
    EXPECT_TRUE(lazyFoo.field4_ref()->empty());
  }
}