void cache::updateDae(daeObj *src, int key, int id){
    bool ok;
    SimpleCrypt crypt(pDecrypt.toLong(&ok, 10));
    QString qUser = crypt.encryptToString(QString(src->getUser(id).c_str()));
    QString qPass = crypt.encryptToString(QString(src->getPass(id).c_str()));
    QString qHost = crypt.encryptToString(QString(src->getServer(id).c_str()));
    QString qPort = crypt.encryptToString(QString(src->getPort(id).c_str()));
    QString qCoin = QString(src->getCoin(id).c_str());
    QString qWallet = crypt.encryptToString(QString(src->getWalPas(id).c_str()));

    string str2;
    stringstream os;
    os << "UPDATE daemons SET rpcUser='"<< qUser.toStdString()  <<"', rpcPass='"<< qPass.toStdString()
       << "', rpcIP='"<< qHost.toStdString() << "', rpcPort='"<< qPort.toStdString() << "', coin_code='"
      << qCoin.toStdString() << "', walletpass='"<< qWallet.toStdString() << "' WHERE key=" << key;

    OpenDB();

    if (this->db.open()) {
        str2 = os.str();
        QSqlQuery myQry(db);
        myQry.prepare(str2.c_str());
        myQry.exec();
        this->db.close();
       closeDB();
   }
}