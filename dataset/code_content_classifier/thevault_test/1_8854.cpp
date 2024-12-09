void blocking(double *vals, int n_vals, int block_size, double *res){

  // note: integer division will waste some values
  int n_blocks = n_vals/block_size;

  /*
  cerr << "n_vals=" << n_vals << ", block_size=" << block_size << endl;
  if(n_vals%block_size > 0)
    cerr << "lost " << n_vals%block_size << " values due to integer division" 
	 << endl;
  */

  double* block_vals = new double[n_blocks];

  for(int i=0; i<n_blocks; i++){
    block_vals[i] = mean(vals+i*block_size, block_size);
  }

  meanvar(block_vals, n_blocks, res);

  delete block_vals;
}