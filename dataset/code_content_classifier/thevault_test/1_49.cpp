int* gen_chall_(int number_of_chall, int bit_size_of_chall, int int_modulus){

    Random rd_;
    int* ar;
    ar = new int[number_of_chall];
    bigint* set, bigint_modulus;
    bool duplicated_ = true;
    set = (bigint*)malloc(number_of_chall * sizeof(bigint));
    // while(duplicated_){// this loop can be commented out/in if duplication is (not) allowed.
    set = rd_.gen_randSet(number_of_chall, bit_size_of_chall);// generate a set of random bigint
    // put them in the range: [0,int_modulus-1]
    mpz_init(bigint_modulus);
    mpz_set_ui(bigint_modulus, int_modulus);
    for (int i = 0; i < number_of_chall; i++){
      mpz_mod(set[i], set[i], bigint_modulus);
      ar[i] = mpz_get_ui(set[i]);
      mpz_clear(set[i]);
    }
     //duplicated_ = is_there_duplicated_elem(ar, number_of_chall);
    //}
    // if(duplicated_){
    //   cout<<"\n\n\t\t*******************************************************"<<endl;
    //   cout<<"\n\n\t\tNOTE: The challange array contains duplicated values--Pick a new array"<<endl;
    //   cout<<"\n\n\t\t*******************************************************"<<endl;
    // }
    return ar;
}