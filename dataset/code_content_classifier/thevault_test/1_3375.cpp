TEST(TEST_BASE, Initialization)
{
    for (int i = 0 ; i < 4; i++)
    {
        ROC_Initialize();
        ROC_Finalize();
    }
}