static int swServer_tcp_sendwait(swServer *serv, int session_id, void *data, uint32_t length)
{
    swConnection *conn = swServer_connection_verify(serv, session_id);
    if (!conn)
    {
        swoole_error_log(SW_LOG_NOTICE, SW_ERROR_SESSION_CLOSED, "send %d byte failed, because session#%d is closed", length, session_id);
        return SW_ERR;
    }
    return swSocket_write_blocking(conn->socket, data, length);
}