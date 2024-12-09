int JsonCalls::setRpcCall(string method){
    string msg = "";
    if(method == "getnewaddress"){
        callType = 2;
    }else if(method == "getreceivedbyaddress"){
        callType = 3;
    }else if(method == "sendfrom"){
        callType = 4;
    }else if(method == "getbalance"){
        callType = 5;
    }else if(method == "getaccount"){
        callType = 6;
    }else if(method == "getaccountaddress"){
        callType = 7;
    }else if(method == "getaccountaddress"){  // get fee wallet
        callType = 8;
    }else if(method == "settxfee"){  // get fee wallet
        callType = 9;
    }else if(method == "gettransaction"){
        callType = 10;
    }else if(method == "service_charge"){
        callType = 11;
    }else if(method == "move"){
        callType = 12;
    }else if(method == "getaccount"){
        callType = 13;
    }else if(method == "getbalance_service"){
        callType = 10004;
    }else{
        callType = 101010;
    }
    return callType;
}