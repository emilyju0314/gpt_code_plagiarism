void OverviewPage::updateWatchOnlyLabels(bool showWatchOnly)
{
    ui->labelSpendable->setVisible(showWatchOnly);      // show spendable label (only when watch-only is active)
    ui->labelWatchonly->setVisible(showWatchOnly);      // show watch-only label
    ui->widgetWatchAvailable->setVisible(showWatchOnly); // show watch-only available balance
    ui->widgetWatchPending->setVisible(showWatchOnly);   // show watch-only pending balance
    ui->widgetWatchTotal->setVisible(showWatchOnly);     // show watch-only total balance

    if (!showWatchOnly)
    {
        ui->widgetWatchImmature->hide();
        ui->widgetWatchStake->hide();
    }

    ui->widgetWatch->setVisible(showWatchOnly);
}