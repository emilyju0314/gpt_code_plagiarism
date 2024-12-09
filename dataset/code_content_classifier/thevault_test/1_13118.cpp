void Adam::Init(XConfig &config)
{
    XOptimizer::Init(config);

    adamBeta1 = config.GetFloat("adambeta1", 0.9F);
    adamBeta2 = config.GetFloat("adambeta2", 0.98F);
    adamDelta = config.GetFloat("adamdelta", 1e-9F);
}