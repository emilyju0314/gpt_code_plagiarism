void MealReccomendGUI::MealDBResult(QNetworkReply* reply){
    QByteArray removingQuotes = reply->readAll();
    while(removingQuotes.indexOf('"') != -1){
        removingQuotes.remove(removingQuotes.indexOf('"'),1);
    }
    std::stringstream output;
    output << removingQuotes.toStdString();

    std::string data;
    std::stringstream dataSplitter;
    std::string splitData[2];
    std::vector<std::string>:: iterator i;
    std::getline(output,data,',');
    while(std::getline(output,data,',')){
        dataSplitter.clear();
        dataSplitter << data;
        std::getline(dataSplitter,splitData[0],':');
        std::getline(dataSplitter,splitData[1]);
        if(splitData[0]=="strCategory"){
            for(i=categories.begin(); i!=categories.end() && *i != splitData[1]; i++);
            if(i==categories.end()) categories.push_back(splitData[1]);
            //add to backend node
        } else if(splitData[0]=="strMeal"){
            this->testingReccomendation = splitData[1];
        } else if(splitData[0]=="strArea"){
            for(i=regions.begin(); i!=regions.end() && *i != splitData[1]; i++);
            if(i==regions.end()) regions.push_back(splitData[1]);
        } else if(splitData[0].size() > 12){
            if(splitData[0].substr(0,13).compare(0,13,"strIngredient")==0){
               // qDebug() << QString::fromStdString(splitData[1]);
            }
        }
    }
    this->inputsAdded++;
}