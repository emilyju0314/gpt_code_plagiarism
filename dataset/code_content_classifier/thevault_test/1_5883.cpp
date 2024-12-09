void DataConnect::openDB(){
     this->db = QSqlDatabase::addDatabase("QMYSQL", "test");
     this->db.setHostName(QString(data->getHost().c_str()));
     this->db.setDatabaseName(QString(data->getName().c_str()));
     this->db.setUserName(QString(data->getUser().c_str()));
     this->db.setPassword(QString(data->getPass().c_str()));

}