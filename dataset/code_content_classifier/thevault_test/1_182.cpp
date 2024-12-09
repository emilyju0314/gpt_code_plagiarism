bool TranslationManager::setCurrentLanguage( QString cl )
{
	 if ( _transData.isEmpty() || !_transData.keys().contains( cl ) )
	 {
		return false;
	 }
	_currentLanguage = cl;
	return true;
}