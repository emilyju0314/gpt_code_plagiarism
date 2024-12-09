void grid_list::dispose(grid_layer *layer)
   {
   delete layer;
   grid_layers::dispose(layer);
   }