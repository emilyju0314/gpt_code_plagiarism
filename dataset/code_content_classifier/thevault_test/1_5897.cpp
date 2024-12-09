void cache::readDB(dbObj &src){
    bool ok;
    SimpleCrypt crypt(pDecrypt.toLong(&ok, 10));

    OpenDB();

       if(this->db.open()){
           QSqlQuery query(db);
           query.prepare("SELECT * FROM database");
           query.exec();
           while (query.next()){
               QString QVal1 = crypt.decryptToString(query.value(1).toString());
               QString QVal2 = crypt.decryptToString(query.value(2).toString());
               QString QVal3 = crypt.decryptToString(query.value(3).toString());
               QString QVal4 = crypt.decryptToString(query.value(4).toString());
               src.set(QVal3.toStdString(),QVal4.toStdString(), QVal1.toStdString(),QVal2.toStdString());
           }
           this->db.close();
           closeDB();
       }
}