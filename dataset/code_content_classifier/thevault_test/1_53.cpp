bool check_query(int* chall, int number_of_chall, int file_size){

  for (int i = 0; i< number_of_chall; i++){
    if(chall[i] > file_size){
      cout<<"\n There exist invalid challenge(s)"<<endl;
      return false;
    }
  }
  return true;
}