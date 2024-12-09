void Messenger :: send_serial_msg(int dest, int compIndex, int inputIndex,
				  Ticks_t sendTick, Ticks_t recvTick, int len)
{

    unsigned msg_type = Message_s :: M_SERIAL;
    int isTick = 1;  //time unit for sendTime/recvTime is tick

    int position = 0;

    MPI_Pack(&msg_type, 1, MPI_UNSIGNED, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&compIndex, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&inputIndex, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&isTick, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    //Ticks_t == uint64_t
    MPI_Pack(&sendTick, 1, MPI_UNSIGNED_LONG_LONG, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&recvTick, 1, MPI_UNSIGNED_LONG_LONG, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&len, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    //MPI_Pack(data, len, MPI_UNSIGNED_CHAR, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    position += len;

    send_message(dest, m_send_buf, position);

    #ifdef DBG_MSG
    #endif

}