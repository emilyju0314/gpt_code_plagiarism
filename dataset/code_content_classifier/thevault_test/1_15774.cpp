TEST(ListWrapperTest, InterLeaveTestII) {
  scoped_ptr<ListWrapperSimple> interleave_list(
    CreateDescendingList(rand() % 2));
  ASSERT_FALSE(interleave_list.get() == NULL);
  ASSERT_FALSE(interleave_list->Empty());

  scoped_ptr<ListWrapperSimple> ascending_list(CreateAscendingList(rand() % 2));
  ASSERT_FALSE(ascending_list.get() == NULL);

  for (unsigned int i = 0; i < kNumberOfElements / 2; ++i) {
    ASSERT_EQ(0, interleave_list->PopBack());
    ASSERT_EQ(0, ascending_list->PopBack());
  }
  ASSERT_EQ(kNumberOfElements / 2, interleave_list->GetSize());
  ASSERT_EQ(kNumberOfElements / 2, ascending_list->GetSize());

  unsigned int insert_position = kNumberOfElements / 2;
  ASSERT_EQ(insert_position * 2, kNumberOfElements);
  while (!ascending_list->Empty()) {
    ListItem* item = ascending_list->Last();
    ASSERT_FALSE(item == NULL);

    const unsigned int item_id = ascending_list->GetUnsignedItem(item);
    ASSERT_EQ(0, ascending_list->Erase(item));

    ListItem* insert_item = interleave_list->CreateListItem(item_id);
    ASSERT_FALSE(insert_item == NULL);
    item = interleave_list->First();
    ASSERT_FALSE(item == NULL);
    for (unsigned int j = 0; j < insert_position - 1; ++j) {
      item = interleave_list->Next(item);
      ASSERT_FALSE(item == NULL);
    }
    EXPECT_EQ(interleave_list->InsertBefore(item, insert_item), 0);
    --insert_position;
  }

  scoped_ptr<ListWrapperSimple> interleaved_list(
    CreateInterleavedList(rand() % 2));
  ASSERT_FALSE(interleaved_list.get() == NULL);
  ASSERT_FALSE(interleaved_list->Empty());

  ASSERT_TRUE(CompareLists(interleaved_list.get(), interleave_list.get()));
}