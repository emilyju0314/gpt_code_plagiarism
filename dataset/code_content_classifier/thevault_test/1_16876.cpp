Nickname NicknamesModel::getItemFromRow(std::vector<QStandardItem *> &row,
                                        const Nickname &original)
{
    return Nickname{row[0]->data(Qt::DisplayRole).toString(),
                    row[1]->data(Qt::DisplayRole).toString()};
}