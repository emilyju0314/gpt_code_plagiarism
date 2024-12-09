bool DataConnect::updateTransCount(int userid){
    stringstream os;
               os << "UPDATE ccdev_billing_summary SET billing_trans = billing_trans + 1, total_trans = total_trans + 1 WHERE user_id =" << userid << endl;
                 cout << os.str() << endl;
        openDB();
        if(db.open()){
            QSqlQuery * query = new QSqlQuery(db);
            query->prepare(os.str().c_str());
            query->exec();
            db.close();
            closeDB();
       }
       return true;
}