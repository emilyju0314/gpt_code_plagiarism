vector<string> Solution::fizzBuzz(int A) {
    vector<string> sol;
    sol.resize(A);
    for(int i = 0; i<A; i++) {
        //Enter Fizz-Buzz logic only if eligibility criteria is followed
        if((i+1)%3==0 || (i+1)%5==0) {
            //Multiples of 3
            if((i+1)%3==0)
                sol[i] += "Fizz";
            //Multiples of 5. Notice that this is an independent 'If'
            //So in case of 15, Fizz has already been printed and now we
            //will print Buzz.
            if((i+1)%5==0)
                sol[i] += "Buzz";
        }
        else
            sol[i] = sol[i] + to_string(i+1);
        
    }
    return sol;
}