XOptimizer * Adam::Clone(int devID)
{
    Adam * opt = new Adam();
    
    Copy(this, opt, devID);
    
    return (XOptimizer*)opt;
}