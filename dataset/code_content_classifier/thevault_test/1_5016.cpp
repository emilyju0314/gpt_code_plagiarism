static void printEntry(const Entry& e) {
	std::cout << "id        : " << e.id << '\n';
	std::cout << "title     : " << e.title << '\n';
	std::cout << "year      : " << e.year << '\n';
	std::cout << "authors   : " << e.authors << '\n';
	std::cout << "citations : " << e.citations << '\n';
	std::cout << "timestamp : " << e.updateTimestamp << '\n';
	std::cout << "snippet   : " << e.snippet << '\n' << std::endl;
}