const string BankAccount::prepareFormattedMiniDetails() const {
	//same as prepareFormattedStatement, but for mini statement - 
	//no need for transaction list since done with produceNMostRecentTransactions
	assert(getAccountType(accountNumber_[0]) != "UNKNOWN");
	ostringstream os;

	os << "\n      ACCOUNT TYPE:    " << getAccountType(accountNumber_[0]) << " ACCOUNT";
	os << "\n      ACCOUNT NUMBER:  " << accountNumber_;
	os << "\n      CREATION DATE:   " << creationDate_.toFormattedString();
	os << fixed << setprecision(2) << setfill(' ');
	os << "\n      BALANCE WITHOUT OVERDRAFT:         \234" << setw(10) << balance_;
	os << "\n      BALANCE WITH OVERDRAFT:         \234" << setw(10) << maxBorrowable();
	os << "\n      ----------------------------------------";
	return os.str();
}