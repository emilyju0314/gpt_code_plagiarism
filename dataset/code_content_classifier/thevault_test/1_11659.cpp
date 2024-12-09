void Library::modifyBooklist()
{
	cls();
	cout << "\t\t\t\t\t********** BOOKLIST MODIFICATION **********\n\n";
	cout << "\t\t\t\t\t>> Choose any option\n\n";
	cout << "\t\t\t\t\t1. Add Books\n\n" << "\t\t\t\t\t2. Remove Books\n\n" << "\t\t\t\t\t3. Issue Book\n\n" << "\t\t\t\t\t4. Return Book\n\n" << "\t\t\t\t\t5. Go Back\n\n";
	cout << "\t\t\t\t\tEnter choice: ";
	int choice;
	cin >> choice;
	cout << endl << endl;
	switch (choice)
	{
	case 1:
		addBooks();
		break;
	case 2:
		removeBook();
		break;
	case 3:
		issueBook();
		break;
	case 4:
		returnBook();
		break;
	case 5:
		cls();
		staff();
		break;
	default:
		cout << "\t\t\t\t\tInvalid choice.\n\n";
		cout << "\t\t\t\t\tPress any key to be able to enter a valid choice\n\n";
		(void)_getch();
		cls();
		modifyBooklist();
	}
}