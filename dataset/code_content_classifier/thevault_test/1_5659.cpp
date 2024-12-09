int MainScreen(){
    Menu:
    welcomeScreen();
     cout<<"\t "<<setfill('\t')<<setw(17) <<"1. Login. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(17) <<"2. About. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(22) <<"3. Developers. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(19) <<"4. Setting. "<<endl;
    cout<<"\t "<<setfill('\t')<<setw(16) <<"5. Exit. "<<endl<<endl;
    cout<<"\t "<<setfill('\t')<<setw(15) <<"Choice: ";
    int choice;
    while(!(cin>>choice))
    {
        FeedBackMessage("Invalid Input", 15);
        cin.clear();
        cin.ignore(20, '\n');
        system("pause");
        //system("cls");
    }

    switch(choice)
    {
    // Print all data in table format
    case 1:
        login();
        break;
    case 2:
        AppHeader("About");
        About();
        AppFooter();
        goto Menu;
    case 3:
        AppHeader("Developers Info");
        Developers();
        AppFooter();
        goto Menu;
        break;
    case 4:
        AppHeader("Setting");
        Settings();
        AppFooter();
        goto Menu;
        break;
    case 5:
        WriteToFile();
        //return 0;
        exit(0);
        break;
}
}