int Library::booksCategory(int flag)
{
	cls();
	cout << "\t\t\t\t\t********** CATEGORY OF BOOKS **********\n\n";
	cout << "\t\t\t\t\t>> Select a Category\n\n";
	cout << "\t\t\t\t\t1. School of Computer Engineering\n\n" << "\t\t\t\t\t2. School of Electronics Engineering\n\n" << "\t\t\t\t\t3. School of Electrical Engineering\n\n" << "\t\t\t\t\t4. School of Mechanical Engineering\n\n" << "\t\t\t\t\t5. School of Civil Engineering\n\n" << "\t\t\t\t\t6. First Year\n\n" << "\t\t\t\t\t7. Go Back\n\n" << "\t\t\t\t\t8. Go to Main Menu\n\n";
	cout << "\t\t\t\t\tEnter choice: ";
	int choice;
	cin >> choice;
	cout << endl << endl;
	switch (choice)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	case 6:
		return 6;
	case 7:
		cls();
		if (flag == 1)
			student();
		else
			staff();
		break;
	case 8:
		cls();
		mainMenu();
		break;
	default:
		cout << "\t\t\t\t\tInvalid choice.\n\n";
		cout << "\t\t\t\t\tPress any key to be able to enter a valid choice\n\n";
		(void)_getch();
		cls();
		booksCategory(flag);
	}
}