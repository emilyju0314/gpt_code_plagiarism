const IMessagePtr MessagesProtocol::sendSync(const IMessagePtr& msg)
{
    ipc::SMessage input_ice = m_converter.msg2ice(msg);
    ipc::SMessage output_ice = m_proxy->sendSync(input_ice);
    return m_converter.ice2msg(output_ice);
}