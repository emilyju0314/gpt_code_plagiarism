void DataConnect::writeTransaction(wrkObj *src, int wrkNum, string tranID, string fee){
    QDateTime current = QDateTime::currentDateTime();

    stringstream os;
    os << "INSERT INTO ccdev_transactions" << " (`basic_id`, `bundle_type`, `uid`, `coin_code`, `sender`, `receiver`, `tranid`, `amount`, `fee`, `status`, `timestamp`)"
          << " VALUES  (NULL, 'withdrawal', " << "\'" << src->getUser(wrkNum) << "\', \'"
          << src->getCoin(wrkNum) << "\', \'" << src->getSender(wrkNum)  << "\', \'"
          << src->getRecipient(wrkNum) << "\', \'" << tranID << "\', \'"
          << src->getAmount(wrkNum) << "\', \'" << fee << "\', \'" << src->getStatus(wrkNum)  << "\', NOW())" <<endl;
    cout << os.str() << endl;

    openDB();
    if(db.open()){
        QSqlQuery * query = new QSqlQuery(db);
        query->prepare(os.str().c_str());
        query->exec();
        db.close();
        closeDB();
   }

}