void CVProcessing::cvAddPoint(int xtrans, int ytrans){
    
    /* this is for landscape left
     iOS
    (0,0)      (1024,0)
     -------------
     |           |
 cam |           | button
     |           |
     -------------
     (0,768)     (1024,768)
     
     
     opencv
    (w,l)        (w,0)
     -------------
     |           |
 cam |           | button
     |           |
     -------------
     (0,l)       (0,0)
     
     */
    
    cv::Size cvwidlen=CVProcessing::gray.size();
    int x = CVProcessing::newpoint[0];
    int y = CVProcessing::newpoint[1];
    //define a c++ vector for points needed for opencv
    std::vector<cv::Point2f> tmp;

    
    //THESE TRANSFORMATIONS WILL NEED TO CHANGE ON ROTATION
    x=xtrans-x;
    y=ytrans-y;
    //these are the points that go into opencv
    CVProcessing::newpoint2f = cv::Point2f(float(cvwidlen.width*x/xtrans),float(cvwidlen.height*y/ytrans));
    tmp.push_back(CVProcessing::newpoint2f);
    //if a new point the find corners - the last points CHECK
    cornerSubPix( CVProcessing::gray, tmp, CVProcessing::winSize, cvSize(-1,-1), CVProcessing::termcrit);
    //put all old points
    CVProcessing::points[1].push_back(tmp[0]);
    tmp.clear();
    newpoint.clear();
}