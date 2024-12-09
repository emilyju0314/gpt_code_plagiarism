TEST(ValueEmscriptenValConversion, EmscriptenValOrDie) {
  {
    constexpr bool kBoolean = false;
    const Value value =
        ConvertEmscriptenValToValueOrDie(emscripten::val(kBoolean));
    ASSERT_TRUE(value.is_boolean());
    EXPECT_EQ(value.GetBoolean(), kBoolean);
  }

  {
    const int kInteger = 123;
    const Value value =
        ConvertEmscriptenValToValueOrDie(emscripten::val(kInteger));
    ASSERT_TRUE(value.is_integer());
    EXPECT_EQ(value.GetInteger(), kInteger);
  }

  {
    emscripten::val object_val = emscripten::val::object();
    object_val.set("foo", emscripten::val::null());

    const Value value = ConvertEmscriptenValToValueOrDie(object_val);
    ASSERT_TRUE(value.is_dictionary());
    EXPECT_EQ(value.GetDictionary().size(), 1U);
    const Value* foo_value = value.GetDictionaryItem("foo");
    ASSERT_TRUE(foo_value);
    EXPECT_TRUE(foo_value->is_null());
  }
}