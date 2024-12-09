XOptimizer * XOptimizer::Clone(int devID)
{
    XOptimizer * opt = new XOptimizer();
    
    Copy(this, opt, devID);
    
    return opt;
}