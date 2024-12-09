void NicknamesModel::getRowFromItem(const Nickname &item,
                                    std::vector<QStandardItem *> &row)
{
    setStringItem(row[0], item.name());
    setStringItem(row[1], item.replace());
}