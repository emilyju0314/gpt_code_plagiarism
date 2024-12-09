void ScriptThread::onGetVariables(const QString &propertyName)
{
	if (mEngine != nullptr) {
		QScriptValueIterator it(mEngine->globalObject().property(propertyName));
		QJsonObject json;
		while (it.hasNext()) {
			it.next();
			json[it.name()] = it.value().toString();
		}
		emit variablesReady(json);
	}
}