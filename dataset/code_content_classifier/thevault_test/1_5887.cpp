void DataConnect::writeFee(wallet *wall){
    stringstream os;
    os << "INSERT INTO ccdev_transactions" << " (`basic_id`, `bundle_type`, `uid`, `coin_code`, `sender`, `receiver`, `amount`, `status`, `timestamp`)"
          << " VALUES  (NULL, 'fee', " << "\'" << wall->getUser() << "\', \'"
          << wall->getCoin() << "\', \'" << wall->getAccount()  << "\', \'"
          << wall->getAddress() << "\', \'" << wall->getStrAmount() << "\', \'"
          << wall->getConfirm()  << "\',NOW())" <<endl;
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