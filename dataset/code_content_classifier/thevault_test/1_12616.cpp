void Messenger :: send_serial_msg(int dest, int compIndex, int inputIndex,
                                  double sendTime, double recvTime, int len)
{
    unsigned msg_type = Message_s :: M_SERIAL;
    int isTick = 0;  //time unit for sendTime/recvTime is not tick

    int position = 0;

    MPI_Pack(&msg_type, 1, MPI_UNSIGNED, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&compIndex, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&inputIndex, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&isTick, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&sendTime, 1, MPI_DOUBLE, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&recvTime, 1, MPI_DOUBLE, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    MPI_Pack(&len, 1, MPI_INT, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    //MPI_Pack(data, len, MPI_UNSIGNED_CHAR, m_send_buf, m_send_buf_size, &position, MPI_COMM_WORLD);
    position += len;

    send_message(dest, m_send_buf, position);

    #ifdef DBG_MSG
    #endif

}