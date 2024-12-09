void Annotate::displayVideo()
{
    // check if we can open video
    if (!openVideo()) { return; }
    // set video to start at frame
    if (!cap.set(CV_CAP_PROP_POS_FRAMES, beginFrame))
    {
    	std::cout << "Error with beginFrame." << std::endl;
    	return;
    }
    // store video frame	
    cv::Mat frame;
    cv::namedWindow("Frame", cv::WINDOW_AUTOSIZE);
    // count frame index
    int fcount = beginFrame;
    // pause flag
    bool pause = false;
    while (fcount != stopFrame)
    {
    	// check if video is paused
    	if (!pause) {
    	    // read new frame
    	    if (!readFrame(frame)) { break; }
    	    // increase frame index
	    fcount++;
	    // check if we reached stopFrame
	    if (!checkFrame(fcount)) { break; }
	    // display frame
	    cv::imshow("Frame", frame);
	}
	// grab user's input
	if (!userVideoControls(pause)) { break; }
    }
    // release resources
    release();
}