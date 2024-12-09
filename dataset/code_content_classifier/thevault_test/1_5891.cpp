bool DataConnect::writeConfirmedBalance(wallet *src, bool withdrawal){
    stringstream os;
    stringstream qry;
    QString qWallConfirm =  QString("%1").arg(src->getAmount(),0,'g',8);

    if(!withdrawal){
        if(src->getFlag() != "expired"){
            qry << " coin_balance= coin_balance + ( " <<  qWallConfirm.toStdString() << " - " << src->getFee() << " )"
            << ", coin_pending= coin_pending - ( " << qWallConfirm.toStdString() << " - " << src->getFee() << " )";
        }else if(src->getFlag() == "expired"){
            qry << " coin_pending= coin_pending - ( " << qWallConfirm.toStdString() << " - " << src->getFee() << " )";
        }
    }else{
        qry << " coin_withdraw= coin_withdraw - " <<  qWallConfirm.toStdString();
    }
    qry<< " , updated= NOW()";
   os << "UPDATE ccdev_balance SET" << qry.str() << " WHERE uid=\'" << src->getUser() << "\' AND coin_code=\'"<<src->getCoin() << "\'" <<endl;
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