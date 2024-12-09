void MadLib() {
    cout << "Welcome to Mad Lib.\n\n";
    cout << "Answer the following questions to help create a new story.\n";

    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNumber("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");

    string* pName = &name;
    string* pNoun = &noun;
    int* pNumber = &number;
    string* pBodypart = &bodyPart;
    string* pVerb = &verb;

    tellStory(pName, pNoun, pNumber, pBodypart, pVerb);
}