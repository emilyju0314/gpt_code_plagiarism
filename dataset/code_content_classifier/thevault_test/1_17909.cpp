int swServer_master_send(swServer *serv, swSendData *_send)
{
    uint32_t session_id = _send->info.fd;
    char *_send_data = _send->data;
    uint32_t _send_length = _send->info.len;

    swConnection *conn;
    if (_send->info.type != SW_SERVER_EVENT_CLOSE)
    {
        conn = swServer_connection_verify(serv, session_id);
    }
    else
    {
        conn = swServer_connection_verify_no_ssl(serv, session_id);
    }
    if (!conn)
    {
        if (_send->info.type == SW_SERVER_EVENT_SEND_DATA)
        {
            swoole_error_log(SW_LOG_NOTICE, SW_ERROR_SESSION_NOT_EXIST, "send %d byte failed, session#%d does not exist", _send_length, session_id);
        }
        else
        {
            swoole_error_log(SW_LOG_NOTICE, SW_ERROR_SESSION_NOT_EXIST, "send event$[%d] failed, session#%d does not exist", _send->info.type, session_id);
        }
        return SW_ERR;
    }

    int fd = conn->fd;
    swReactor *reactor = SwooleTG.reactor;

    if (!serv->single_thread)
    {
        assert(fd % serv->reactor_num == reactor->id);
        assert(fd % serv->reactor_num == SwooleTG.id);
    }

    if (serv->factory_mode == SW_MODE_BASE && conn->overflow)
    {
        if (serv->send_yield)
        {
            SwooleG.error = SW_ERROR_OUTPUT_SEND_YIELD;
        }
        else
        {
            swoole_error_log(SW_LOG_WARNING, SW_ERROR_OUTPUT_BUFFER_OVERFLOW, "connection#%d output buffer overflow", fd);
        }
        return SW_ERR;
    }

    swSocket *_socket = conn->socket;

    /**
     * Reset send buffer, Immediately close the connection.
     */
    if (_send->info.type == SW_SERVER_EVENT_CLOSE && (conn->close_reset || conn->peer_closed))
    {
        goto _close_fd;
    }
    /**
     * pause recv data
     */
    else if (_send->info.type == SW_SERVER_EVENT_PAUSE_RECV)
    {
        if (_socket->removed || !(_socket->events & SW_EVENT_READ))
        {
            return SW_OK;
        }
        if (_socket->events & SW_EVENT_WRITE)
        {
            return reactor->set(reactor, conn->socket, SW_EVENT_WRITE);
        }
        else
        {
            return reactor->del(reactor, conn->socket);
        }
    }
    /**
     * resume recv data
     */
    else if (_send->info.type == SW_SERVER_EVENT_RESUME_RECV)
    {
        if (!_socket->removed || (_socket->events & SW_EVENT_READ))
        {
            return SW_OK;
        }
        if (_socket->events & SW_EVENT_WRITE)
        {
            return reactor->set(reactor, _socket, SW_EVENT_READ | SW_EVENT_WRITE);
        }
        else
        {
            return reactor->add(reactor, _socket, SW_EVENT_READ);
        }
    }

    if (swBuffer_empty(_socket->out_buffer))
    {
        /**
         * close connection.
         */
        if (_send->info.type == SW_SERVER_EVENT_CLOSE)
        {
            _close_fd:
            reactor->close(reactor, _socket);
            return SW_OK;
        }
        //Direct send
        if (_send->info.type != SW_SERVER_EVENT_SEND_FILE)
        {
            if (!_socket->direct_send)
            {
                goto _buffer_send;
            }

            ssize_t n;

            _direct_send:
            n = swSocket_send(_socket, _send_data, _send_length, 0);
            if (n == _send_length)
            {
                return SW_OK;
            }
            else if (n > 0)
            {
                _send_data += n;
                _send_length -= n;
                goto _buffer_send;
            }
            else if (errno == EINTR)
            {
                goto _direct_send;
            }
            else
            {
                goto _buffer_send;
            }
        }
        //buffer send
        else
        {
            _buffer_send:
            if (!_socket->out_buffer)
            {
                _socket->out_buffer = swBuffer_new(SW_SEND_BUFFER_SIZE);
                if (_socket->out_buffer == NULL)
                {
                    return SW_ERR;
                }
            }
        }
    }

    swBuffer_chunk *chunk;
    //close connection
    if (_send->info.type == SW_SERVER_EVENT_CLOSE)
    {
        chunk = swBuffer_new_chunk(_socket->out_buffer, SW_CHUNK_CLOSE, 0);
        if (chunk == nullptr)
        {
            return SW_ERR;
        }
        chunk->store.data.val1 = _send->info.type;
        conn->close_queued = 1;
    }
    //sendfile to client
    else if (_send->info.type == SW_SERVER_EVENT_SEND_FILE)
    {
        swSendFile_request *req = (swSendFile_request *) _send_data;
        if (swSocket_sendfile(conn->socket, req->filename, req->offset, req->length) < 0)
        {
            return SW_ERR;
        }
    }
    //send data
    else
    {
        //connection is closed
        if (conn->peer_closed)
        {
            swWarn("connection#%d is closed by client", fd);
            return SW_ERR;
        }
        //connection output buffer overflow
        if (_socket->out_buffer->length >= _socket->buffer_size)
        {
            if (serv->send_yield)
            {
                SwooleG.error = SW_ERROR_OUTPUT_SEND_YIELD;
            }
            else
            {
                swoole_error_log(SW_LOG_WARNING, SW_ERROR_OUTPUT_BUFFER_OVERFLOW, "connection#%d output buffer overflow", fd);
            }
            conn->overflow = 1;
            if (serv->onBufferEmpty && serv->onBufferFull == NULL)
            {
                conn->high_watermark = 1;
            }
        }

        if (swBuffer_append(_socket->out_buffer, _send_data, _send_length) < 0)
        {
            swWarn("append to pipe_buffer failed");
            return SW_ERR;
        }

        swListenPort *port = swServer_get_port(serv, fd);
        if (serv->onBufferFull && conn->high_watermark == 0 && _socket->out_buffer->length >= port->buffer_high_watermark)
        {
            serv->notify(serv, conn, SW_SERVER_EVENT_BUFFER_FULL);
            conn->high_watermark = 1;
        }
    }

    //listen EPOLLOUT event
    if (reactor->set(reactor, _socket, SW_EVENT_WRITE | SW_EVENT_READ) < 0 && (errno == EBADF || errno == ENOENT))
    {
        goto _close_fd;
    }

    return SW_OK;
}