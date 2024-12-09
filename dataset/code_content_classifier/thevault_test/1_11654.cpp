void Library::getData()
{
	cin.ignore();
	cout << "\t\t\t\t\t********** ENTER BOOK DETAILS **********";
	cout << "\n\n\n\t\t\tEnter Book's Name: ";
	cin.getline(book, 100);
	cout << "\n\t\t\tEnter Author's Name: ";
	cin.getline(author, 100);
	cout << "\n\t\t\tEnter Publication Name: ";
	cin.getline(publication, 100);
	cout << "\n\t\t\tEnter Book's ID: ";
	cin >> id;
	cout << "\n\t\t\tEnter Book's Price: ";
	cin >> price;
	cout << "\n\t\t\tEnter Book's Quantity: ";
	cin >> quantity;
}