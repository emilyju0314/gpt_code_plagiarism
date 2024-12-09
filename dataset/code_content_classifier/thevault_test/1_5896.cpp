void cache::generateAPI(){

    SimpleCrypt crypt(atol(APICache));
   string str2, apikey = "";
   stringstream os;
   QString qAPI = crypt.encryptToString(QString(APIKey));

   /// Check if API KEY exists
   apikey = checkAPI();

    if(apikey == ""){
        os << "INSERT INTO preferences (apikey) VALUES ('" << qAPI.toStdString() << "')";
    }else{
        os << "UPDATE preferences SET apikey='"<< qAPI.toStdString() << "'";
    }

   OpenDB();

   if (this->db.open()) {
       str2 = os.str();
       QSqlQuery myQry(db);
       myQry.prepare(str2.c_str());
       myQry.exec();
       this->db.close();
      closeDB();
  }
  qDebug() << "Your new API KEY: " << qAPI.toStdString().c_str() << endl;
}