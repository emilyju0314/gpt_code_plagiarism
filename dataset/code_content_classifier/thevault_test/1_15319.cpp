bool Annotate::readFrame(cv::Mat& frame)
{
    if (!cap.read(frame))
    {
    	//std::cout << "End of file." << std::endl;
    	return false;
    }
    else {
    	return true;
    }
}