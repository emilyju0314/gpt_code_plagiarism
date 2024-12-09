void cache::updateDB(dbObj *src){
    bool ok;
    SimpleCrypt crypt(pDecrypt.toLong(&ok, 10));

    string str2;
    stringstream os;

    QString qUser = crypt.encryptToString(QString(src->getUser().c_str()));
    QString qPass = crypt.encryptToString(QString(src->getPass().c_str()));
    QString qHost = crypt.encryptToString(QString(src->getHost().c_str()));
    QString qTable = crypt.encryptToString(QString(src->getName().c_str()));

    os << "UPDATE database SET user='"<< qUser.toStdString()  <<"', pass='"<< qPass.toStdString() <<"',ip_address='"<< qHost.toStdString() << "', dbname='"<< qTable.toStdString() << "' WHERE key=1";
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