ArrayBO EchoBay::esn_train(YAML::Node confParams, Reservoir &ESN, const double lambda,
                      const std::string problemType, const std::string fitnessRule,
                      const std::string outputFolder, const DataStorage &store, const bool saveflag, 
                      const int guesses)
{
    // ESN general Parameters
    // Deep ESN
    int nLayers = ESN.get_nLayers();
    // Readout blockStep
    int blockStep = confParams["blockStep"].as<int>();

    // Construct comparator class
    Comparator fitter(problemType, fitnessRule);

    // Calculate readout matrix depending on the problem
    ArrayI8 trainSampling = store.get_sampleArray(EchoBay::Train);
    MatrixBO targetMatrix = fitter.get_targetMatrix(store.get_data(EchoBay::Train, EchoBay::selLabel), trainSampling);

    // Calculate Wout as readout layer
    MatrixBO Wout = readout_train(ESN, store, targetMatrix, lambda, blockStep);
    // Calculate prediction states
    // stateMat is already initialized with last training state

    // If saveflag is set, save the trainingState before being overwritten by evalState
    std::vector<ArrayBO> saveState;
    if (saveflag)
    {
        saveState.reserve(nLayers);
        saveState = ESN.stateMat;
    }

    MatrixBO prediction = readout_predict(ESN, store, Wout, blockStep);

    // Calculate fitness
    // Resize output
    fitter.set_label_size(prediction.rows(), prediction.cols());
    // Get fitness
    ArrayI8 evalSampling = store.get_sampleArray(EchoBay::Valid);
    fitter.set_targetLabel(store.get_data(EchoBay::Valid, EchoBay::selLabel), evalSampling);
    floatBO fitness = fitter.get_fitness(prediction);

    MatrixBO outputLabel;
    outputLabel = fitter.get_outputlabel();

    // Consider memory penalization
    floatBO memory = ESN.return_net_dimension(confParams);
    ArrayBO multiFitness(2);
    multiFitness(0) = fitness;
    multiFitness(1) = memory;

    // Flag used to save just when the parameters have been chosen
    // See main.cpp for clarity
    if (saveflag)
    {
        if (!boost::filesystem::exists(outputFolder))
        {
            boost::filesystem::create_directories(outputFolder);
        }
        //write_matrix<MatrixBO>(outputFolder + std::string("/State.csv"), biasedState);
        std::string tempName;
        for (int i = 0; i < nLayers; ++i)
        {
            tempName = "/Win_eigen" + std::to_string(i) + ".mtx";
            //saveMarket(ESN.WinLayers[0], outputFolder + tempName);
            write_matrix<MatrixBO>(outputFolder + tempName, ESN.WinLayers[i]);
            tempName = "/Wr_eigen" + std::to_string(i) + ".mtx";
            //write_matrix<MatrixBO>(outputFolder + tempName, ESN.WrLayers[i]);
            saveMarket(ESN.WrLayers[i], outputFolder + tempName);

            tempName = "/State_eigen" + std::to_string(i) + ".mtx";
            write_matrix<MatrixBO>(outputFolder + tempName, saveState[i]);
            //saveMarket(Wout, outputFolder + std::string("/Wout_eigen.mtx"));
        }

        std::string nameOut;
        nameOut = "/outputLabel_" + std::to_string(guesses) + ".csv";
        write_matrix<MatrixBO>(outputFolder + std::string(nameOut), prediction);

        nameOut = "/final_state_" + std::to_string(guesses) + ".dat";
        write_array<ArrayBO>(outputFolder + std::string("/final_state.dat"), saveState[nLayers - 1]);

        write_matrix<MatrixBO>(outputFolder + std::string("/Wout_eigen.dat"), Wout);

        if (confParams["Guesses"].as<int>() == (guesses + 1))
        {
            std::cout << "Computation ended \n";
        }
    }

    //return fitness - MemoryPenFactor * Memory;
    return multiFitness;
}