bool VerifyOrder(int* a_testData, int a_dataLength)
{
    for(int i = 0; i < a_dataLength - 1; ++i)
    {
        if(a_testData[i] > a_testData[i + 1])
        {
            return false;
            break;
        }
    }
    return true;
}