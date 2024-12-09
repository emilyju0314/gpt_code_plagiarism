ArrayI8 EchoBay::DataStorage::init_array(const int size, const std::string &problemType, const std::string &fitnessFunction)
{
    if (problemType == "Classification")
    {
        return ArrayI8::Constant(size, 0);
    }
    else if (problemType == "Regression" || problemType == "MemoryCapacity")
    {
        return ArrayI8::Constant(size, 1);
    }
    else // Unsupervised
    {
        return fitnessFunction == "KMeans" ? ArrayI8::Constant(size, 0) : ArrayI8::Constant(size, 1);
    }
}