void cache::updateGrp(grpobj *src, int key, int id){
    bool ok;
    SimpleCrypt crypt(pDecrypt.toLong(&ok, 10));
    QString qName = crypt.encryptToString(QString(src->getName(id).c_str()));
    QString qWFee = crypt.encryptToString(QString(src->getWithdrawFee(id).c_str()));
    QString qTFee = crypt.encryptToString(QString(src->getTradeFee(id).c_str()));
    QString qXFee = crypt.encryptToString(QString(src->getExchangeFee(id).c_str()));
    QString qMFee = crypt.encryptToString(QString(src->getMonthlyFee(id).c_str()));

    string str2;
    stringstream os;
    os << "UPDATE groups SET name='"<< qName.toStdString() << "', withdraw_fee='"<< qWFee.toStdString()
       << "', trade_fee='"<< qTFee.toStdString() << "', exchange_fee='"  << qXFee.toStdString()
       << "', monthly_fee='"<< qMFee.toStdString() << "' WHERE key=" << key;

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