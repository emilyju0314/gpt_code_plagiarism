void DelegationStakerItemModel::updateAmountColumnTitle()
{
    columns[Weight] = BitcoinUnits::getAmountColumnTitle(walletModel->getOptionsModel()->getDisplayUnit());
    Q_EMIT headerDataChanged(Qt::Horizontal,Weight,Weight);
}