Travel find_cheapest(vector<Travel>& travels, vector<vector<string> >&alliances){
  Travel result;
  if(travels.size()>0){
    result = travels.back();
    travels.pop_back();
  }else
    return result;
  while(travels.size()>0){
    Travel temp = travels.back();
    travels.pop_back();
    if(compute_cost(temp, alliances) < compute_cost(result, alliances)){
      result = temp;
    }
  }
  return result;
}