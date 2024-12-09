void Path::sendToFile(string filename){
  ofstream out;
  out.open(filename);

  if(!out.is_open()){
    cout << "Could not open file " << filename << endl;
  }else{
    for(int i=0; i<size(); i++){
      out << get(i).toString << endl;
    }
    out.close();
  }
}