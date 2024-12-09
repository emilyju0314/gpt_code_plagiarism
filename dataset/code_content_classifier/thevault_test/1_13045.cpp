void grid_list::dispose(unsigned int n)
   {
   delete grid_layers::get(n);
   grid_layers::dispose(n);
   }