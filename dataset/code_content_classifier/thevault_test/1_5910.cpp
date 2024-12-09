QJsonObject JsonCalls::standardCall(QVariant id, QVariant name,  QVariant param, QVariant param2, QVariant amount, QVariant confirms){

    QJsonObject json;
    QJsonArray all_params;

    json["method"] = name.toString();
    if(callType == 2){    /// gen wallet - account
           all_params.append(param.toString());
    }
    else if(callType == 3){    /// confirm transaction  - wallet - confirm Num
        all_params.append(param.toString());
        all_params.append(param2.toInt());
    }else if(callType == 4 || callType == 11 || callType == 10001 || callType == 10002 || callType == 10003 || callType == 12 || callType == 10005){    /// send - walletA to walletB || withdrawal
        all_params.append(param.toString());
        all_params.append(param2.toString());
        all_params.append(amount.toDouble());
    }else if(callType == 5 || callType == 10004){  /// checkbalance
        all_params.append(param.toString());
        all_params.append(param2.toInt());
    }else if(callType == 6){    /// getaccount  // by address
         all_params.append(param.toString());
    }else if(callType == 7){    /// getaccount  // by address
        all_params.append(param.toString());
    }else if(callType == 8){    /// getaccount  // by address
        all_params.append(param.toString());
    }else if(callType == 9){    /// settx fee
        all_params.append(amount.toDouble());
    }else if(callType == 10){    /// gettransaction // by tranid
        all_params.append(param.toString());
    }else if(callType == 13){    /// gettransaction // by tranid
        all_params.append(param.toString());
    }

     json.insert("params", all_params);
     json["id"] = id.toInt();

     return json;
}