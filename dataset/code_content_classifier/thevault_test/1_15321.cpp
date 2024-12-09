bool Annotate::checkFrame(int findex)
{
    if (findex == stopFrame)
    {
    	//std::cout << "Reached stop frame." << std::endl;
    	return false;
    }
    else { return true; }
}