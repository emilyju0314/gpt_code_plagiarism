void LoadProduct()
{
    // define variables
    string tempString,line;
    Product temp;
    //number of lines
    int i = 0;

    fstream SuperMarket;
    SuperMarket.open("Products.txt", ios::app | ios::out | ios::in ); //opening the file.
    if (SuperMarket.is_open()) //if the file is open
    {
        //ignore first line

        while (getline(SuperMarket,line)) //while the end of file is NOT reached
        {
            stringstream ss(line);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductNumber= stoi(tempString);
            getline(ss, temp.ProductName, ',');
            getline(ss, temp.Category, ',');
            getline(ss, temp.ProductType, ',');
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Day = stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Month=stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ProductionDate.Year=stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Day= stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Month= stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.ExpireDate.Year= stoi(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.Quantity = stof(tempString);
            getline(ss, temp.MeasurementUnit, ',');
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.UnitPrice= stof(tempString);
            getline(ss, tempString, ',');
            tempString= removeSpaces(tempString);
            temp.Rating= stof(tempString);
            getline(ss, tempString, '\n');
            tempString= removeSpaces(tempString);
            temp.Sales = stoi(tempString);
            Products.push_back(temp);
            i++; //increment number of lines
        }
        SuperMarket.close(); //closing the file
    }
    else cout << "Unable to open file"; //if the file is not open output
}