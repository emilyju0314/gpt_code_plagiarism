bool DataConnect::writeConfirmWallet(wallet *src, int orderid, bool final, bool CONFIRMED, bool walExists){
    stringstream os, is, qry;
    string flag;

    if(!walExists){
        flag = src->getFlag();
    }else{
        flag = "-";
    }
    if(!final){  /// we're confirming for balance update
        qry << " fee_total="<< src->getFee() << ", last_processed_id="<< orderid << ", flag=\'"<< "-"<< "\', pending_total= pending_total + "<< src->getStrAmount() << " , timestamp= NOW()"<<endl;
   }else{
   qry << " last_processed_id="<< orderid << ", balance_total="<< src->getStrAmount() << ", flag=\'"<< flag<< "\', pending_total=0, timestamp= NOW()" << endl;
  }

    if(CONFIRMED){
        qry << ", confirm=" << src->getConfirm();
    }



  //  os << "UPDATE ccdev_wallets SET" << qry.str() << " WHERE walletaddress=\'" << src->getAddress() << "\'" <<endl;
     os << "UPDATE " << qry.str() <<endl;

    is << "INSERT INTO ccdev_wallets" << " (`basic_id`, `bundle_type`, `uid`, `orderid`, `balance_total`, `pending_total`, `fee_total`, `coins_enabled`, `walletaddress`, `walletaccount`, `last_processed_id`, `confirm`, `flag`,`timestamp`)"
          << " VALUES  (NULL, 'work_order', " << "\'" << src->getUser() << "\', \'" << orderid << "\', \'" << 0 <<"\', \'"<< src->getStrAmount() << "\', \'"<< src->getFee() << "\', \'" << src->getCoin() << "\', \'"
          << src->getAddress() << "\', \'" << src->getAccount() << "\',\'"<< orderid  << "\',\'"<< src->getConfirm() << "\',\'"<< flag <<"\',NOW()) ON DUPLICATE KEY "<< os.str() <<endl;

    cout << is.str() << endl;

    openDB();
      if(db.open()){
           QSqlQuery * query = new QSqlQuery(db);
               query->prepare(QString(is.str().c_str()));
               query->exec();
              db.close();
              closeDB();
      }
}