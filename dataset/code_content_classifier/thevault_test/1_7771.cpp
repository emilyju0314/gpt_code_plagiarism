void heapRebuild(unsigned data[], 
		 unsigned index[],
                 unsigned root,
                 unsigned size)

{
  if (! isLeafInHeap( root, size))//if the root is not a leaf 
    {
      //root must have a left child
      unsigned child = 2 * root + 1;

      if  (hasRightChildInHeap(root, size))
	{

          unsigned rightChild = child +1;
          
          if ( data[rightChild] < data[child])
	    child = rightChild ;

	}//end if
   
      if (  data[child] <  data[root]) 
	{

	  // swap root and child

	  unsigned temp = data[root];
	  data[root] = data[child];
	  data[child] = temp;

	  temp = index[root];
	  index[root] = index[child];
	  index[child] = temp;

	  heapRebuild( data, index, child, size);

	}//end if
          
    }//end if 

  //else root is a leaf, so we are done.

}