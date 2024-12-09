void TrainingConfig::Load(int argsNum, const char **args)
{
    Create(argsNum, args);

    LoadString("train", trainFN, "");
    LoadString("valid", validFN, "");

    LoadBool("adam", &useAdam, true);

    LoadInt("nepoch", &nepoch, 50);
    LoadInt("nstep", &nstep, 100000);
    LoadInt("savefreq", &saveFreq, 10000);
    LoadInt("nwarmup", &nwarmup, 8000);
    LoadInt("updatefreq", &updateFreq, 1);
    LoadInt("ncheckpoint", &ncheckpoint, 10);
    
    LoadFloat("lrbias", &lrbias, 0);
    LoadFloat("lrate", &lrate, 0.0015F);
    LoadFloat("minlr", &minLR, 1e-9F);
    LoadFloat("warmupinitlr", &warmupInitLR, 1e-7F);
    LoadFloat("adambeta1", &adamBeta1, 0.9F);
    LoadFloat("adambeta2", &adamBeta2, 0.98F);
    LoadFloat("adamdelta", &adamDelta, 1e-9F);
    LoadFloat("labelsmoothing", &labelSmoothingP, 0.1F);
    LoadFloat("weightdecay", &weightDecay, 0.0F);
    isTraining = (strcmp(trainFN, "") == 0) ? false : true;
    incremental = false;
}