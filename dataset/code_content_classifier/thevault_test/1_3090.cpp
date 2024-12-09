bool IscConnection::isAvailable(thread_db* tdbb, TraScope traScope) const
{
	const int flags = m_provider.getFlags();
	if (m_used_stmts && !(flags & prvMultyStmts))
		return false;

	if (m_transactions.getCount() && !(flags & prvMultyTrans) && !findTransaction(tdbb, traScope))
	{
		return false;
	}

	return true;
}