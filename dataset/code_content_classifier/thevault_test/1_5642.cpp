void welcomeScreen()
{
    cout << "\n\n" << endl;
    ChangeLineColor(10);
    cout << R"(
                        ,ad8888ba,                                     ad88888ba   88
                       d8"'    `"8b                            ,d     d8"     "8b  88)";
    ChangeLineColor(11);
    cout << R"(
                      d8'                                      88     Y8,          88
                      88             ,adPPYYba,  8b,dPPYba,  MM88MMM  `Y8aaaaa,    88,dPPYba,    ,adPPYba,   8b,dPPYba,)";
    ChangeLineColor(12);
    cout << R"(
                      88             ""     `Y8  88P'   "Y8    88       `"""""8b,  88P'    "8a  a8"     "8a  88P'    "8a
                      Y8,            ,adPPPPP88  88            88             `8b  88       88  8b       d8  88       d8)";
    ChangeLineColor(13);
    cout << R"(
                       Y8a.    .a8P  88,    ,88  88            88,    Y8a     a8P  88       88  "8a,   ,a8"  88b,   ,a8"
                        `"Y8888Y"'   `"8bbdP"Y8  88            "Y888   "Y88888P"   88       88   `"YbbdP"'   88`YbbdP"' )";
    ChangeLineColor(13);
    cout << R"(
                                                                                                             88
                                                                                                             88
    )" << endl;
    ChangeLineColor(14);
    cout << endl;
    cout << "\t\t\t\t\t\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t\t\t\t\t\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << endl;
}