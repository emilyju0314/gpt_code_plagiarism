void readAndEchoCharResponse (char & response)
{
    char junk;  // Holds chars that trail the desired response char.

    cin >> response;
    while (cin.get() != '\n'); // Clear the line.
    cout << response << endl;
}