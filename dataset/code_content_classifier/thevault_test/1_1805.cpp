void MealReccomendGUI::on_Generate_clicked()
{
    if(ui->complexity->value() == 1){
        ui->errorMessages->setText("unable to generate suggestions, try setting complexity value to a higher number");
        ui->errorMessages->show();
        return;
    }else if(ui->complexity->value()==0){
        UserPreferences->recipeComplexity = -1;
    }else{
        UserPreferences->recipeComplexity = ui->complexity->value();
    }
    ui->errorMessages->hide();


    // adding positive ingredients to userPreferences
    UserPreferences->positiveIngredients.clear();
    for(int i=0; i < ui->Positives_list->count(); i++){
        UserPreferences->positiveIngredients.push_back(ui->Positives_list->item(i)->text().toStdString());
    }
    //Seperating negative ingredients from their weight
    // and adding both to userPreferences
    UserPreferences->negativeIngredients.clear();
    UserPreferences->negativeIngredientsWeight.clear();
    for(int i=0; i < ui->Negatives_list->count(); i++){
        QString inputtedText = ui->Negatives_list->item(i)->text();
        if(inputtedText.endsWith("0")){
            UserPreferences->negativeIngredientsWeight.push_back(10);
            inputtedText.remove("10");
        } else {
            UserPreferences->negativeIngredientsWeight.push_back(inputtedText.at(inputtedText.length()-1).digitValue());
            inputtedText.remove(inputtedText.length()-1, 1);
        }
        inputtedText.remove(" - ");
        UserPreferences->negativeIngredients.push_back(inputtedText.toStdString());
    }
    // Adding regional food preferences to userPreferences
    if(ui->regionalFood->currentIndex()>0) UserPreferences->regionPositive = ui->regionalFood->currentText().toStdString();
    else UserPreferences->regionPositive = "";

    if(ui->neg_Region->currentIndex()>0) UserPreferences->regionNegative = ui->neg_Region->currentText().toStdString();
    else UserPreferences->regionNegative = "";

    // adding catagory preferences to userPreferences
    if(ui->food_type->currentIndex()>0)
        UserPreferences->foodStylePositive = ui->food_type->currentText().toStdString();
    else
        UserPreferences->foodStylePositive = "";

    if(ui->negFood_type->currentIndex()>0) UserPreferences->foodStyleNegative = ui->negFood_type->currentText().toStdString();
    else UserPreferences->foodStyleNegative = "";

    // Sending userPreferences to backEnd

    // sending backend to window 2
    qDebug() << QString::fromStdString(this->testingReccomendation);
    window2->showReccomendations(this->testingReccomendation);
    //this->hide();
    window2->show();



}