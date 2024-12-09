void Shell::setShellConstants(std::map<std::string, double> shellConstants)
{
    std::string msg;
    std::map<std::string, double>::const_iterator c_it;

    for (c_it = shellConstants.begin(); c_it != shellConstants.end(); ++c_it)
    {
        if(this->shellConstants.find(c_it->first) != this->shellConstants.end())
        {
            this->shellConstants[c_it->first] = c_it->second;
        }
        else
        {
            msg = "Invalid constant " + c_it->first + " for " + this->name +" shell";
            throw std::invalid_argument(msg);
        }
    }
}