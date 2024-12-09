void CNRGmatrix::FilterMap_SetBegEnd(){

// Original
// [e1 e2 e3 e4 e5]
// [(b1 b2), (b1 b2), (b4 b5), (b4 b5), (b5 b6) ]
//
// End up with
//
// [e1 e2 e3 e4 e5]
//[(b1 b2) (b4 b5) (b5 b6) ]
//[(0 1),(2 3), (4 4)] 
// 

//
// Note: needs that MatBlockMap entering to have two indexes *per element*
//

  vector<int>::iterator map_iter,map_iter2;
  vector<int>::iterator it;
   int ipos=0;
   int nelblock=0;

   MatBlockBegEnd.clear();


   cout << "Setting up MatBlockBegEnd: " << endl;

   for (map_iter=MatBlockMap.begin(); map_iter<MatBlockMap.end(); 
       map_iter+=2)
     {
       MatBlockBegEnd.push_back(ipos);


       nelblock=1;
       map_iter2=map_iter+2;
       it=search(map_iter2,MatBlockMap.end(),
		 map_iter,map_iter+1);
       // Search for sequence map_iter,map_iter+1
//        while (it!=MatBlockMap.end())
// 	 {
// 	   cout << "Found repetition. MatBlockMap size =  " 
// 		<< MatBlockMap.size() << endl;
// 	   nelblock++;
// 	   MatBlockMap.erase(it,it+2);
// 	   it=search(map_iter2,MatBlockMap.end(),
// 		     map_iter,map_iter+1);
// 	 }

       while (map_iter2<MatBlockMap.end())
	 {
	   if ( (*map_iter2==*map_iter)&&(*(map_iter2+1)==*(map_iter+1))  )
	     {
	       nelblock++;
	       MatBlockMap.erase(map_iter2,map_iter2+2);
	       map_iter2-=2;

	     }
	   map_iter2+=2;
	 }


       ipos+=nelblock;

       MatBlockBegEnd.push_back(ipos-1);

     }

}