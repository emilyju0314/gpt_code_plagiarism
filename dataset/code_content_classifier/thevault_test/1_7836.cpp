unsigned
shorestStringSize(const vector<string> &strings
                  )
{
    unsigned minSize = ~0;

    for (unsigned i = 0; i < (unsigned) strings.size(); i++) {
        unsigned s = strings.at(i).length();

        if (s < minSize)
            minSize = s;

    }//end for

    return minSize;

}