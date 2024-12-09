ArrayBO EchoBay::esn_compute(YAML::Node confParams, Reservoir &ESN, const DataStorage &store, 
                        const std::string &problemType, const std::string &fitnessRule, 
                        const int blockStep, Eigen::Ref<MatrixBO> Wout, 
                        const std::string &outputFolder, const bool saveflag, const int guesses)
{
    Comparator fitter(problemType, fitnessRule);
    ArrayI8 evalSampling = store.get_sampleArray(EchoBay::Valid);
    fitter.set_targetLabel(store.get_data(EchoBay::Valid, EchoBay::selLabel), evalSampling);

    // Compute Prediction
    MatrixBO prediction = readout_predict(ESN, store, Wout, blockStep);

    // Calculate fitness
    // Resize output
    fitter.set_label_size(prediction.rows(), prediction.cols());
    // Get fitness
    floatBO fitness = fitter.get_fitness(prediction);
    MatrixBO outputLabel;

    outputLabel = fitter.get_outputlabel();

    // Consider memory penalization
    floatBO memory = ESN.return_net_dimension(confParams);
    ArrayBO multiFitness(2);

    multiFitness(0) = fitness;
    multiFitness(1) = (memory);
    std::cout << "Computation ended \n";

    if (saveflag)
    {
        std::string nameOut;
        nameOut = "/outputLabel_" + std::to_string(guesses) + ".csv";
        write_matrix<MatrixBO>(outputFolder + std::string(nameOut), prediction);

        // TODO move this to compute prediction
        //nameOut = "/final_state_" + std::to_string(guesses) + ".dat";
        //write_array<ArrayBO>(outputFolder + std::string(nameOut), valState.row(valPoints - 1));
    }
    return multiFitness;
}