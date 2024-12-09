void PrintReceipt()
{
    int Choice;
    system("cls");
    welcomeScreen();
    ChangeLineColor(14);
    cout<<setfill(' ')<<setw(30)<<"Receipt\n";
    cout<<setfill(' ')<<"Item No"<<setw(15)<<"Name \t"<<setw(8)<<"Quantity"<<setw(8)<<"Price"<<setw(10)<<"Amount\n";
    ChangeLineColor(15);
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        ChangeLineColor(14);
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        cout<<setfill(' ')<<"Item "<<i+1<<": "<<setw(15)<<Products[N].ProductName<<setw(8)<<Quantity[i]<<setw(8)<<Products[N].UnitPrice<<setw(10)<<Quantity[i]*Products[N].UnitPrice<<endl;
        ChangeLineColor(15);
        cout << "\t-" << setfill('-') << setw(50) << "-" << endl;
        ChangeLineColor(14);
        TotalPrice=TotalPrice+(Quantity[i]*Products[N].UnitPrice);
    }

    cout<<setfill(' ')<<setw(47)<<"Txbl   "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Tax(15%)   "<<0.15*TotalPrice<<endl;
    TotalPrice=1.15*TotalPrice;
    cout<<setfill(' ')<<setw(47)<<"TotalPrice  "<<TotalPrice<<endl;
    cout<<setfill(' ')<<setw(47)<<"Cash: ";
    cin>>Cash;
    cout<<setfill(' ')<<setw(47)<<"Change: "<<Cash-TotalPrice<<endl;
    for(int i=0; i<NumberofBoughtItems; i++)
    {
        int N;
        N=Location[i];
        Products[N].Quantity=Products[N].Quantity-Quantity[i];
        Products[N].Sales = Products[N].Sales + Quantity[i];
    }
     cout<<setfill(' ')<<setw(30)<<"Thank You For Your Purchase" << endl;
     system("pause");
      cout<<setfill(' ')<<setw(30)<<"To Perform another Sales Press 1, To Return to MainMenu Press 2, To exit Press 3;" << endl;
      Menu:
      cout<<setfill(' ')<<setw(30)<<"Choice: ";
      while(!(cin>>Choice))
    {
        ChangeLineColor(12);
        cout<<"Error! Invalid Input\n";
        cin.clear();
        cin.ignore(20, '\n');
        ChangeLineColor(14);
        goto Menu;
    }
    switch(Choice)
    {
        case 1:
            system("cls");
            CashierAccount();
            break;
        case 2:
            system("cls");
            MainScreen();
            break;
        case 3:
          WriteToFile();
         exit(0);
         break;
         default:
            ChangeLineColor(12);
            cout<<"Error!Choose a Correct Number\n";
            system("pause");
            system("cls");
            ChangeLineColor(14);
            goto Menu;
            break;


    }

}