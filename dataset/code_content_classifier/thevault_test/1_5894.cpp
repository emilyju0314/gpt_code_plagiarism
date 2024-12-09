bool DataConnect::writeModifiedBalance(int userID, string balance, string coin_code){
    stringstream os;
    stringstream qry;

    qry << " coin_balance= " << balance.c_str() << " - coin_pending," << " updated= NOW()";
   os << "UPDATE ccdev_balance SET" << qry.str() << " WHERE uid=\'" << userID << "\' AND coin_code=\'"<<coin_code << "\'" <<endl;
  cout << os.str() << endl;
    openDB();
      if(db.open()){
           QSqlQuery * query = new QSqlQuery(db);
               query->prepare(QString(os.str().c_str()));
               query->exec();
              db.close();
              closeDB();
      }
      return true;
}