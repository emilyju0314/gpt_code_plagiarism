void CVProcessing::cvOrigin(int x, int y, int xtrans, int ytrans){
    cv::Size cvwidlen=CVProcessing::gray.size();
    //define a c++ vector for points needed for opencv
    std::vector<cv::Point2f> origin2f;

 //THESE TRANSFORMATIONS WILL NEED TO CHANGE ON ROTATION
    x=xtrans-x;
    y=ytrans-y;
    //these are the points that go into opencv
    CVProcessing::origin2f.push_back(cv::Point2f(float(cvwidlen.width*x/xtrans),float(cvwidlen.height*y/ytrans)));
}