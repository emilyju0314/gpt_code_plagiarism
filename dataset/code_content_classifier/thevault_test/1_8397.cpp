bool MemWrapper::getMemReq(Request &req){
    std::list<Request>::iterator it;
    if(reqQueue.empty() == false){
        Request tmp = reqQueue.front();
        shallowReqCopy(tmp, req);
        req.udf.arriveMemTime = (long)(sc_time_stamp()/sc_time(1, SC_NS));
        reqQueue.pop_front();
        return true;
    }
    else{
        return false;
    }
}