void List::printList( ){

    if (getElementCount()==0)
    {
        cout << "There are 0 patients in the list" << endl;
    }
    
    else
    {
    for( int i = 0; i < 10; i++)
        {
            for( int j = 0; j <elementCount[i]; j++)
            {
                cout<< elements[i][j].getCareCard() <<", "<< "Patient: "<< elements[i][j].getName() <<", "<< elements[i][j].getAddress() <<", "<< elements[i][j].getPhone() <<", "<< elements[i][j].getEmail() << endl;
        
            }
        }
    }
}