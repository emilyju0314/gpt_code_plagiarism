void LoadScientistsFromFileDialog::on_ButtonLoad_clicked()
{
    file = ui->InputForTextFileName->text().toStdString();
    load = true;
    this->close();
}