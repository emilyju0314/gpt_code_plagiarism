EchoBay::Comparator::Comparator(const std::string &problemType, const std::string &fitnessRule)
{
    // Assign internal variables
    _problemType = problemType;
    _fitnessRule = fitnessRule;
    try
    {
        switch(problemTypes.at(problemType))
        {
            // Regression
            case 0:
                if (fitnessRule == "MSA")
                {
                    fitnessFunction = MSA;
                }
                else
                {
                    fitnessFunction = NRMSE;
                }
                break;
            // Classification
            case 1:
                if (fitnessRule == "F1Mean")
                {
                    fitnessFunction = F1Mean;
                }
                else
                {
                    fitnessFunction = Accuracy;
                }
                break;
            // Memory capacity
            case 3:
                fitnessFunction = MemoryCapacity;
                break;
            // External function
#ifdef USE_PYBIND
            case 4:
                fitnessFunction = ExtFitness;
                break;
#endif
        }
    } 
    catch (const std::exception &e)
    {
        std::cout << "Undefined problemType" << std::endl;
    }
}