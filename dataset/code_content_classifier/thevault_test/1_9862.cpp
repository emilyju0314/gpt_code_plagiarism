void
AttributeGroup::CreateTypeMap(const char *formatString)
{
    // Clear the typeMap.
    typeMap.clear();

    // If the format string is NULL, return.
    if(formatString == NULL)
        return;

    // If the formatString was empty, get out of here.
    int nDeclares = static_cast<int>(strlen(formatString));
    if(nDeclares < 1)
        return;

    // Go through the format string and add the types.
    typeMap.reserve(nDeclares);
    for(int i = 0; i < nDeclares; ++i)
    {
        char baseFormat = formatString[i];

        // If the next character is a '*' then it is a vector.
        bool isVector = (i < nDeclares - 1) ? (formatString[i + 1] == '*') :
                        false;

        if(isVector)
        {
            // Advance one character
            ++i;

            // Declare vectors
            switch(baseFormat)
            {
            case 'b':
                DeclareVectorBool();
                break;
            case 'c':
                DeclareVectorChar();
                break;
            case 'u':
                DeclareVectorUnsignedChar();
                break;
            case 'i':
                DeclareVectorInt();
                break;
            case 'l':
                DeclareVectorLong();
                break;
            case 'f':
                DeclareVectorFloat();
                break;
            case 'd':
                DeclareVectorDouble();
                break;
            case 's':
                DeclareVectorString();
                break;
            case 'a':
                DeclareVectorAttributeGroup();
                break;
            default:
                EXCEPTION0(BadDeclareFormatString);
            }
        }
        else
        {
            // Declare simple types, fixed length, attributegroups
            switch(baseFormat)
            {
            case 'c':
                DeclareChar();
                break;
            case 'u':
                DeclareUnsignedChar();
                break;
            case 'i':
                DeclareInt();
                break;
            case 'l':
                DeclareLong();
                break;
            case 'f':
                DeclareFloat();
                break;
            case 'd':
                DeclareDouble();
                break;
            case 's':
                DeclareString();
                break;
            case 'a':
                DeclareAttributeGroup();
                break;
            case 'b':
                DeclareBool();
                break;
            case 'C':
                DeclareListChar();
                break;
            case 'U':
                DeclareListUnsignedChar();
                break;
            case 'I':
                DeclareListInt();
                break;
            case 'L':
                DeclareListLong();
                break;
            case 'F':
                DeclareListFloat();
                break;
            case 'D':
                DeclareListDouble();
                break;
            case 'S':
                DeclareListString();
                break;
            case 'A':
                DeclareListAttributeGroup();
                break;
            case 'B':
                DeclareListBool();
                break;
            default:
                EXCEPTION0(BadDeclareFormatString);
            }
        }
    }
}