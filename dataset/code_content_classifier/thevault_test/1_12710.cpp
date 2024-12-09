GMMCluster::GMMCluster(int init_num_of_subclasses, Option option1)
:mOption(option1)
{
	mDesiredNumCluster=init_num_of_subclasses*-1;
	mSig=NULL;
}