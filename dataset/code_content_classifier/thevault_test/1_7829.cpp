bool
testConsistent(const vector<unsigned> &result1,
               const vector<unsigned> &result2)
{
    if (result1.size() != result2.size())
        return false;

    UnsignedSet s1(result1.begin(), result1.end());
    UnsignedSet s2(result2.begin(), result2.end());

    UnsignedSet::iterator ite1 = s1.begin();
    UnsignedSet::iterator ite2 = s2.begin();

    while (ite1 != s1.end()) {
        if (*ite1 != *ite2)
            return false;

        ite1++;
        ite2++;

    }//end while

    return true;

}