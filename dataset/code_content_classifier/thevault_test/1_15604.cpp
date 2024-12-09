void printMenuAndGetAction (char & response)
{
    cout << "\n\n";
    cout << "Which of the following actions do you wish to take?\n";
    cout << "   B)uild or modify the current tree interactively.\n";
    cout << "   C)ount the number of sibling pairs in the tree.\n";
    cout << "   D)etermine whether the tree is height balanced.\n";
    cout << "   G)row new leaves on the current tree.\n";
    cout << "   P)rint the current tree on the screen.\n";
    cout << "   Q)uit.\n";
    cout << "   S)um the data in the leaves of the tree.\n";
    cout << "\n";
    cout << "Your choice:  ";
    
    readAndEchoCharResponse (response);
    
    while (1) // loop will continue until user gives an appropriate response
    {
        switch (response)
        {
        case 'B': case 'b': case 'C': case 'c': 
        case 'D': case 'd': case 'P': case 'p': 
        case 'Q': case 'q':
        case 'S': case 's': case 'G': case 'g':
            return;  // EXIT FROM THE FUNCTION WITH PARAMETER HAVING OK VALUE 
        default : cout << "Improper Response  "
                "Please type an appropriate letter.   ";
        }
        readAndEchoCharResponse (response);
    }
}