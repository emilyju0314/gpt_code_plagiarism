void UndoStackItemSelectionModel::select(const QModelIndex& index, QItemSelectionModel::SelectionFlags command)
{
    if (!model())
    {
        return;
    }

    if (index.isValid())
    {
        QItemSelectionModel::select({ model()->index(0, 0, {}), index }, command);
    }
    clearCurrentIndex();
}