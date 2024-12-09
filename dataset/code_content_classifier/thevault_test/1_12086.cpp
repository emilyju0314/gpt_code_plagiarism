void ConnectionManager::removeConnection(unsigned int connectionId)
{
    Connection* conn = getConnection(connectionId);
    if (conn)
    {
        Q_EMIT beforeConnectionRemoved(connectionId);
        conn->SetAutoConnect(false);
        conn->Terminate();
    }
}