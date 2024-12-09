bool DataConnect::writeGeneratedWallet(wallet *wall, wrkObj *src, int workNum){
    stringstream os;

     os << "INSERT INTO ccdev_wallets" << " (`basic_id`, `bundle_type`, `uid`, `orderid`, `balance_total`, `pending_total`, `fee_total`, `coins_enabled`, `walletaddress`, `walletaccount`, `last_processed_id`, `confirm`, `timestamp`)"
           << " VALUES  (NULL, 'work_order', " << "\'" << src->getUser(workNum) << "\', \'" << src->getOrderID(workNum) << "\', \'0\', \'0\', \'0\', \'" << src->getCoin(workNum) << "\', \'"
           << wall->getAddress() << "\', \'" << wall->getAccount() << "\',\'"<< src->getOrderID(workNum)  << "\',0,NOW())" <<endl;

     cout << os.str() << endl;

     openDB();
       if(this->db.open()){
            QSqlQuery * query = new QSqlQuery(db);
                query->prepare(QString(os.str().c_str()));
                query->exec();
             this->db.close();
             closeDB();
       }
       return true;

}