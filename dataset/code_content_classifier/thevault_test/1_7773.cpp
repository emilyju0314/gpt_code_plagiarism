void heapInsert(unsigned newData,
                unsigned newIndex,
                unsigned data[],
                unsigned index[],
                unsigned &size)

{

  // insert newItem into the bottom of the tree

  data[size] = newData;
  index[size] = newIndex;

  // trickle new item up to appropriate spot in the tree

  unsigned place = size;

  unsigned parent = (place-1)/2;


  
  while ( (place >= 1) &&
          data[place] < data[parent]  
        )       
    {
      // swap place and parent 

      unsigned temp = data[parent];
      data[parent] = data[place];
      data[place] = temp;

               
      temp = index[parent];
      index[parent] = index[place];
      index[place] = temp;

      place = parent;

      parent = (place-1)/2;
  
    }//end while

  ++size;
 

}