bool Annotate::userVideoControls(bool& pause)
{
    char key = cv::waitKey(delay);
    if (key == char('q'))
    {
    	//std::cout << "Video closed." << std::endl;
    	return false;
    }
    else if (key == char('p'))
    {
    	//if (!pause) { std::cout << "Video paused." << std::endl; }
    	//else { std::cout << "Video unpaused." << std::endl; }
    	pause = !pause;
    	return true;
    }
    else { return true; }
}