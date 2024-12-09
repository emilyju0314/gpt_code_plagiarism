void MealReccomendGUI::updateInfo(){

    if(this->inputsAdded == NUMBER_OF_RECIPES_ADDED){

        this->timer.stop();
        for(unsigned int i=0; i < categories.size(); i++){
            qDebug() << QString::fromStdString(categories.at(i));
            ui->food_type->addItem(QString::fromStdString(categories.at(i)));
            ui->negFood_type->addItem(QString::fromStdString(categories.at(i)));
        }
        for(unsigned int i=0; i< regions.size(); i++){
            qDebug() << QString::fromStdString(regions.at(i));
            ui->regionalFood->addItem(QString::fromStdString(regions.at(i)));
            ui->neg_Region->addItem(QString::fromStdString(regions.at(i)));
        }
        qDebug() << categories.size() << " " << regions.size();
    }
}