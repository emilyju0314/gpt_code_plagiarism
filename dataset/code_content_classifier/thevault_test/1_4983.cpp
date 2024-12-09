void CVProcessing::cvDeletePoint(){
    if (!CVProcessing::points[0].empty()){
        CVProcessing::points[0].pop_back();
        CVProcessing::points[1].pop_back();
    }
}