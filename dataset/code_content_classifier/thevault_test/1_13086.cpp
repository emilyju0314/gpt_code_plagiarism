float XLearningRate::MakeLRTransformer(const float lrate, const int nstep, const int nwarmup, const float warmupInitLR)
{
    float lr = 0.0F;
    float warmupEndLR = lrate;
    float lrStep = (warmupEndLR - warmupInitLR) / nwarmup;
    float decayFactor = warmupEndLR * pow(float(nwarmup), 0.5F);

    /* learning rate, scheduled by inverse square root */
    if (nstep < nwarmup)
        lr = warmupInitLR + nstep * lrStep;
    else
        lr = decayFactor * pow((float)nstep, -0.5F);

    return lr;
}