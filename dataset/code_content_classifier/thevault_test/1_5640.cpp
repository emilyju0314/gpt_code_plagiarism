void loadAccount()
{
    // define variables
    string line;
    Account temp;
    //number of lines
    fstream AccountDetail;
    AccountDetail.open("Accounts.txt", ios::app | ios::out | ios::in ); //opening the file.
    if (AccountDetail.is_open()) //if the file is open
    {
        //ignore first line
        while (getline(AccountDetail,line)) //while the end of file is NOT reached
        {
            stringstream ss(line);
            getline(ss,temp.Name,',');
            getline(ss,temp.position,',');
            getline(ss,temp.userName,',');
            getline(ss,temp.password);
            Accounts.push_back(temp);
        }
        AccountDetail.close(); //closing the file
    }
    else cout << "Unable to open file"; //if the file is not open output
}