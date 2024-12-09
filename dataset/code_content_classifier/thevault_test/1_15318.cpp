bool Annotate::openVideo()
{
    // open video
    cap.open(vidPath);
    // check if we succeeded
    if (!cap.isOpened())
    { 
    	std::cout << "Could not open video." << std::endl;
    	return false;
    }
    else
    {
    	//std::cout << "Video opened." << std::endl;
    	return true;
    }
}