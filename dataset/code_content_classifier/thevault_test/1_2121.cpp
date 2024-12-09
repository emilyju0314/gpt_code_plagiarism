LoanManager::~LoanManager()
{
    exit(0);
    for(int loanCount = 0; loanCount < numberOfLoans; loanCount++)
    {
        myLoans[loanCount].~Loan();
    }
}