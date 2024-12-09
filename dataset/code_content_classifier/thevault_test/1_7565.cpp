void write_vect(char *fn,vector<realtype> res)
{
    ofstream output(fn);
    vector<realtype>::iterator it1 = res.begin();
    while(it1!=res.end())
    {
        output << (*it1) << endl;
        it1++;
    }
    output.close();
}