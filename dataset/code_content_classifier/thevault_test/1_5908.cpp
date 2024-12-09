void JsonCalls::regularJson(QJsonObject &json, int id, string action, string sender, string recipient, string fAmount, string confirms){

    qDebug()  << "method = " << action.c_str()  << "Param1 = " << sender.c_str()  << "Param2 = " << recipient.c_str() << "amount = " <<fAmount.c_str() << "id = " << id;

   QVariant dID(id);                                                          ///rpc request id
          QVariant name(QString(action.c_str())),                /// rpc request method
           param(QString(sender.c_str())),               /// rpc request method param1
           param2(QString(recipient.c_str())),           /// rpc request method param2
           param3(QString(confirms.c_str())),             /// rpc request confirmations
           amount(QString(fAmount.c_str()));              /// rpc request confirmations

  json = this->standardCall(dID, name, param, param2, amount, param3);
}