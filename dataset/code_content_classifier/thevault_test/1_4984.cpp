void CVProcessing::cvTracking(cv::Mat image, bool newPoints, int xtrans, int ytrans){
    cv::cvtColor(image, CVProcessing::gray, CV_RGBA2GRAY);
    size_t i, k;
    
    if (newPoints){
        CVProcessing::cvAddPoint( xtrans,  ytrans);
    }
    if (CVProcessing::cvTrackedPoints()!=0){
        if (!CVProcessing::previous.empty()){
            cv::calcOpticalFlowPyrLK(CVProcessing::previous, CVProcessing::gray, CVProcessing::points[0], CVProcessing::points[1], CVProcessing::status, CVProcessing::err, CVProcessing::winSize, 3, CVProcessing::termcrit,0,0.001);
        }
        for(i = k = 0; i < CVProcessing::points[1].size(); i++ ){
            if( !CVProcessing::status[i] )
                continue;
            CVProcessing::points[1][k++] = CVProcessing::points[1][i];
            cv::circle(image, CVProcessing::points[1][i], 3, cv::Scalar(0,255,0), -1, 8);
        }
        CVProcessing::points[1].resize(k);
    }
    if (!CVProcessing::origin2f.empty()){
        cv::circle(image, CVProcessing::origin2f[0], 3, cv::Scalar(255,255,0), -1, 8);
    }
    std::swap(CVProcessing::points[1],CVProcessing::points[0]);
    CVProcessing::gray.copyTo(CVProcessing::previous);
    
}