void Library::student()
{
	cls();
	cout << "\t\t\t\t\t********** WELCOME STUDENT **********\n\n";
	cout << "\t\t\t\t\t>> Choose any option\n\n";
	cout << "\t\t\t\t\t1. View Category of Books\n\n" << "\t\t\t\t\t2. Search for a Book\n\n" << "\t\t\t\t\t3. Go to Main Menu\n\n" << "\t\t\t\t\t4. Exit Application\n\n";
	cout << "\t\t\t\t\tEnter choice: ";
	int choice;
	cin >> choice;
	cout << endl << endl;
	switch (choice)
	{
	case 1:
		viewBooks(1);
		break;
	case 2:
		searchBook(1);
		break;
	case 3:
		cls();
		mainMenu();
		break;
	case 4:
		exit(0);
	default:
		cout << "\t\t\t\t\tInvalid choice.\n\n";
		cout << "\t\t\t\t\tPress any key to be able to enter a valid choice\n\n";
		(void)_getch();
		cls();
		student();
	}
}