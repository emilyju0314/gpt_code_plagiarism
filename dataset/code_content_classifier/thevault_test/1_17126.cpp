TEST(MessageDifferencerTest, FieldContextParentFieldsTest) {
  protobuf_unittest::TestDiffMessage msg1;
  msg1.add_rm()->set_c(1);
  protobuf_unittest::TestDiffMessage msg2;
  msg2.add_rm()->set_c(1);

  ParentSavingFieldComparator field_comparator;
  util::MessageDifferencer differencer;
  differencer.set_field_comparator(&field_comparator);
  differencer.Compare(msg1, msg2);

  // We want only one parent with the name "rm"
  ASSERT_EQ(1, field_comparator.parent_fields().size());
  EXPECT_EQ("rm", field_comparator.parent_fields()[0].field->name());
}