void cache::readGrp(grpobj &src){
    src.init(10);
    bool ok;
    SimpleCrypt crypt(pDecrypt.toLong(&ok, 10));

    OpenDB();
       if(this->db.open()){
           QSqlQuery query(db);
           query.prepare("SELECT * FROM groups");
           query.exec();
           while (query.next()){
               QString QVal1 = crypt.decryptToString(query.value(1).toString());
               QString QVal2 = crypt.decryptToString(query.value(2).toString());
               QString QVal3 = crypt.decryptToString(query.value(3).toString());
               QString QVal4 = crypt.decryptToString(query.value(4).toString());
               QString QVal5 = crypt.decryptToString(query.value(5).toString());
               QString QVal6 = crypt.decryptToString(query.value(6).toString());

               src.set(QVal1.toInt(),QVal2.toStdString(), QVal3.toStdString(),QVal4.toStdString(), QVal5.toStdString(),QVal6.toStdString());
           }
           this->db.close();
           closeDB();
       }
}