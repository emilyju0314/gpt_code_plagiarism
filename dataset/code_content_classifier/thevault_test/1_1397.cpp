QJsonDocument Chat::jsonCreateChatRequest(const Friend &recipient) const {
    QJsonObject args_obj;
    QJsonObject root_obj;
    QString key;
    QString value;

    root_obj["messageType"] = "CHAT_REQUEST";
    root_obj["method"] = "chat";

    args_obj["fromID"] = (int) (m_ChatSender.getID());
    args_obj["toID"] = (int) recipient.getID();
    args_obj["toNick"] = QString::fromStdString(recipient.getNickname());

    root_obj.insert("args", args_obj);

    return QJsonDocument(root_obj);
}