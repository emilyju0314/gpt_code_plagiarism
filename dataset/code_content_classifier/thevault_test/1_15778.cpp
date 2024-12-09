void ListSanity(ListWrapper& list)
{
    if(list.Empty())
    {
      return;
    }
    ListItem* item_iter = list.First();
    // Fake a previous value for the first iteration
    int previous_value = GetStoredIntegerValue(item_iter) - 1;
    while (item_iter != NULL)
    {
        const int value = GetStoredIntegerValue(item_iter);
        FailTest(value != previous_value + 1);
        previous_value = value;
        item_iter = list.Next(item_iter);
    }
}