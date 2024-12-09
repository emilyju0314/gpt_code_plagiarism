TEST(basics)
{
    TEST_ASSERT(
        3 == dummytest(1, 2, 3));
    TEST_ASSERT(
        3 == dummytest(3, 2, 1));
    TEST_ASSERT(
        3 == dummytest(1, 3, 2));
}