void rpcCall::DaemonReply(QNetworkReply *src){
         QString strReply = (QString)src->readAll();
         QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
         QJsonObject jsonArr = jsonResponse.object();
    int rpcid = 0;
    string sRpcID = "";
    QJsonValue val = jsonArr.value(QString("id"));
    rpcid = (int)(val.toDouble());
   // qDebug() << jsonArr << endl;  // test json output

    if(src->error() == QNetworkReply::NoError) { ////  <----- VALID REPLY

             if(rpcid != 0){
                 qDebug() << jsonArr << endl;  // test json output (remove in PROD)
                 emit parseAndWrite(&jsonArr);
            }
         }else{
            /* if(rpcid == 9999){
                 emit unlocked();
             } */
             if(rpcid != 0){
                 qDebug() << jsonArr << endl;  // test json output (remove in PROD)
                emit parseError(&jsonArr);
             }
         }
    src->deleteLater();
}