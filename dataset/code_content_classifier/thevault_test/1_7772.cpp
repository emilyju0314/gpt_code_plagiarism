void heapReplaceHead(unsigned newData,
		     unsigned data[],
		     unsigned index[],
		     unsigned size)

{

  // replace the newItem as the top of the tree

  data[0] = newData;

  heapRebuild(data,index,0,size);

}