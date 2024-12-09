bool DataConnect::writeFeeBalance(int userID, string amount, string coin_code, bool addremove){
    stringstream os;
    stringstream qry;
    if(addremove == false){ /// remove from balance
        qry << " coin_balance= coin_balance -" << amount.c_str() << ", updated= NOW()";
    }else{  /// add to balance
        qry << " coin_balance= coin_balance +" << amount.c_str() << ", updated= NOW()";
    }

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