void MealReccomendGUI::on_regionalFood_currentIndexChanged(int index)
{
    int justToGetThatWarningAway = index;
    justToGetThatWarningAway++;
    resetConfirmed = false;
    ui->reset->setText("Reset Inputs");

}