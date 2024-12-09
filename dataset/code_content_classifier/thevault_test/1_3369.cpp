TEST(TEST_BASE, String_Manipulation)
{
    const char string_orig[] = "Use numba for AMD GPUs!";
    char * string_copy =  ROC_CreateString(string_orig);
    ASSERT_TRUE(string_copy != nullptr);
    ASSERT_STREQ(string_orig, string_copy);
    ROC_DisposeString(string_copy);
}