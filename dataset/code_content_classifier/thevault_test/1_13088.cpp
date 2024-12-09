void XOptimizer::Init(XConfig &config)
{
    nstep = config.GetInt("nstep", 100000);
    nepoch = config.GetInt("nepoch", 50);
    lrate = config.GetFloat("lrate", 0.1F);
}