QByteArray rpcCall::getRequestParam(QJsonObject *json){
    QJsonDocument doc(*json);
   QString result(doc.toJson());
   QByteArray postData;
    postData.append(result);
    return postData;
}