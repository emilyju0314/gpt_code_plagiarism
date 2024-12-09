void DataConnect::writeBill(wallet *wall, int grpid, string grpname){
    stringstream os;
    os << "INSERT INTO ccdev_billing" << " (`basic_id`, `bundle_type`, `user_id`, `grp_id`, `grp_name`, `paid_amt`, `paid_coin`, `paid_date`)"
          << " VALUES  (NULL, 'service_charge', " << "\'" << wall->getUser() << "\', \'"
          << grpid << "\', \'"<< grpname << "\', \'" << wall->getFee()  << "\', \'"
          << wall->getCoin() << "\', NOW())" <<endl;
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