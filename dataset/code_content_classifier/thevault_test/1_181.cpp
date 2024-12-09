bool DbManager::checkDatabase( QString path )
{
	if( !QFileInfo(path).exists() )
	{
		C_ERROR( "No Database %s", QS2CS( path ) );
		return false;
	}
	
	_db = QSqlDatabase::addDatabase("QSQLITE", DBConnectionName);
	_db.setDatabaseName( path );
	_db.open();
/*	{
		C_ERROR( "Can't open Database %s", QS2CS( path ) );
		return false;
	}
*/
	
	QString sql = QString("SELECT meta_information_value FROM db_meta_information WHERE meta_information_key='schema_version' ");
	QSqlQuery query(_db);
	if ( !query.exec(sql) )                 //old schema because the table db_meta_information doesn't exist
	{

		C_ERROR( "Invalid schema on %s", QS2CS( path ) );
		return false;
	}
	else if ( query.record().count() != 1 ) //old schema because meta_information_value has no/redundant value/s
	{
		C_ERROR( "Invalid or redundant schema-version on %s", QS2CS( path ) );
		return false;
	}
									  
	query.next();
	QString sh_stored = query.value(0).toString();
	QString sh_req = schemaHash();
	if ( sh_stored != sh_req )
	{
		C_ERROR( "Invalid schema-version on %s", QS2CS( path ) );
		return false;                       //old schema because meta_information_value has wrong value
	}

	return true;
}