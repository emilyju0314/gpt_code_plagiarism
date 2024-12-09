void DataConnect::updateTransaction(wallet *src, int wrkNum, string tranID){
    stringstream os;
    stringstream qry;

    qry << "amount=" << src->getStrAmount() << " , status=" << src->getConfirm() << " , timestamp= NOW()";

        os << "UPDATE ccdev_transactions SET " << qry.str() << " WHERE tranid=\'" << tranID << "\'" <<endl;
   cout << os.str() << endl;


    qDebug() << src->getStrAmount().c_str() << " = STR AMOUNT IN WALLET" << endl;
    qDebug() << src->getAmount() << "  = AMOUNT DBL IN WALLET" << endl;

    openDB();
      if(db.open()){
           QSqlQuery * query = new QSqlQuery(db);
               query->prepare(QString(os.str().c_str()));
               query->exec();
              db.close();
              closeDB();
      }

}