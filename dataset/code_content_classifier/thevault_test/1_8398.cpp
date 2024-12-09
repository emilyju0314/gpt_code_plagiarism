void MemWrapper::shallowReqCopy(const Request &simpleReq, Request &req){
    req.type = simpleReq.type;
    req.coreid = simpleReq.coreid;
    req.addr = simpleReq.addr;
    req.udf.burstIdx = simpleReq.udf.burstIdx;
    req.udf.reqIdx = simpleReq.udf.reqIdx;
    req.udf.peIdx = simpleReq.udf.peIdx;
    req.udf.portIdx = simpleReq.udf.portIdx;
    req.udf.arriveMemTime = simpleReq.udf.arriveMemTime;
    req.udf.departMemTime = simpleReq.udf.departMemTime;
}