ArrayBO EchoBay::esn_caller(const Eigen::VectorXd &optParams, YAML::Node confParams, 
                       const std::string outputFolder, const DataStorage &store, 
                       const bool guessEval, const std::string &computationType, 
                       const std::string &matrixFolder)
{
    // Number of guesses
    int guesses = confParams["Guesses"].as<int>();

    MatrixBO fitnessMatrix(guesses, 2);
    ArrayBO fitnessOut;

    // Problem settings
    double lambda = parse_config<double>("lambda", -1, 0, optParams, confParams, 0);
    std::string problemType = confParams["Problem_Definition"]["type"].as<std::string>();
    std::string fitnessRule = confParams["Problem_Definition"]["Fitness_Function"].as<std::string>();
    // Readout blockStep
    int blockStep = confParams["blockStep"].as<int>();
    // Limits
    int Nu = store.get_dataCols(EchoBay::Train) + 1;

    // Build Reservoir object
    if (computationType == "train")
    {
#ifdef _OPENMP
        omp_lock_t guessLock;
        omp_init_lock(&guessLock);
#pragma omp parallel for
#endif
        for (int i = 0; i < guesses; i++)
        {
            Reservoir ESN = esn_config(optParams, confParams, Nu, i, "");
            // Call rest of execution
            fitnessMatrix.row(i) = esn_train(confParams, ESN, lambda, problemType, fitnessRule, outputFolder, store, guessEval, i);
#ifdef _OPENMP
            omp_set_lock(&guessLock);
#endif
            std::cout << "Guess: " << i << " ";
            std::cout << "multifitness " << fitnessMatrix.row(i) << std::endl;
#ifdef _OPENMP
            omp_unset_lock(&guessLock);
#endif
        }

        // Calculate output: Train = Mean, Test = Worst Case
        if (guessEval)
        {
            fitnessOut = fitnessMatrix.colwise().minCoeff();
        }
        else
        {
            fitnessOut = fitnessMatrix.colwise().mean();
        }
    }
    else
    {
        std::cout << "Testing optimal configuration on unknown data" << std::endl;
        for (int i = 0; i < guesses; i++)
        {
            Reservoir ESN = esn_config(optParams, confParams, Nu, i, matrixFolder);
            std::string tempName = matrixFolder + "/Wout_eigen.dat";
            MatrixBO Wout;
            read_matrix(tempName, Wout);
            fitnessMatrix.row(i) = esn_compute(confParams, ESN, store, problemType, fitnessRule, blockStep, Wout, outputFolder, guessEval, i);
        }

        // Only worst case in compute
        fitnessOut = fitnessMatrix.colwise().minCoeff();
    }

    std::cout << "Final multiFitness :" << fitnessOut.transpose() << std::endl;
    return fitnessOut;
}