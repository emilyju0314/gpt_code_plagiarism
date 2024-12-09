vector<int> Solution::primesum(int A) {
    //Sieve bool array
    bool *sieve = new bool[A+1];
    //Initialising statements
    fill_n(sieve, A+1, true);
    sieve[0] = false;
    sieve[1] = false;
    vector<int> solution;
    //Constructing the Sieve
    for(int i = 2; i<=sqrt(A+1); i++) {
        if(sieve[i] == false)
            continue;
        for(int j = i+i; j<=A; j+=i)
            sieve[j] = false;
    }
    //Iterating over the sieve to find the solution
    for(int i = 2; i<=A; i++) {
        //For each 'i' we simply check if 'A-i' is also prime.
        //So we don't need to explicitly check for the sum equals A.
        if(sieve[i] == true && sieve[A-i] == true) {
            solution.push_back(i);
            solution.push_back(A-i);
            break;
        }
    }
    return solution;
}