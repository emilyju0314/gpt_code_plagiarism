double *segment_matrix_index(double* theIm, int width, int height, int depth, float sigma, float c, int min_size,
			  int *num_ccs) {

  // Make a vector of image channels
  std::vector<image<float>* > imChannels(depth);
  for (int i = 0; i < depth; i++){
      imChannels[i] = new image<float>(width, height);
  }
  
  // Fill each color channel
  for (int y=0; y < height; y++){
      for (int x = 0; x < width; x++){
          for (int z = 0; z < depth; z++){
              imRef(imChannels[z], x, y) = theIm[y + height * x + height * width * z];
          }
      }
  }

  // Smooth each color channel 
  std::vector<image<float>* > smoothedIm(depth);
  for (int i = 0; i < depth; i++){
      smoothedIm[i] = smooth(imChannels[i], sigma);
      delete imChannels[i];
  }

  // Get minimum and maximum, this in order to make the threshold always similar regardless of
  // what kind of image is put in and in which range
  float minIm = imRef(smoothedIm[0], 0, 0);
  float maxIm = imRef(smoothedIm[0], 0, 0);
  float currVal;
  for (int y=0; y < height; y++){
      for (int x = 0; x < width; x++){
          for (int z = 0; z < depth; z++){
              currVal = imRef(smoothedIm[z], x, y);
              if (currVal > maxIm){
                  maxIm = currVal;
              }
              if (currVal < minIm){
                  minIm = currVal;
              }
          }
      }
  }
  float diffIm = maxIm - minIm;

  // Adjust threshold parameter c based on the difference in the image.
  c = c * diffIm / 255.0;

  // build graph
  edge *edges = new edge[width*height*4];
  int num = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (x < width-1) {
	edges[num].a = y * width + x;
	edges[num].b = y * width + (x+1);
	//edges[num].w = diffVec(smooth_r, smooth_g, smooth_b, x, y, x+1, y);
	edges[num].w = diffVec(smoothedIm, x, y, x+1, y);
	num++;
      }

      if (y < height-1) {
	edges[num].a = y * width + x;
	edges[num].b = (y+1) * width + x;
	//edges[num].w = diffVec(smooth_r, smooth_g, smooth_b, x, y, x, y+1);
	edges[num].w = diffVec(smoothedIm, x, y, x, y+1);
	num++;
      }

      // Commented code below to get 4-connectivity
      /*
      if ((x < width-1) && (y < height-1)) {
	edges[num].a = y * width + x;
	edges[num].b = (y+1) * width + (x+1);
	//edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y+1);
	edges[num].w = diff(smoothedIm, x, y, x+1, y+1);
	num++;
      }

      if ((x < width-1) && (y > 0)) {
	edges[num].a = y * width + x;
	edges[num].b = (y-1) * width + (x+1);
	//edges[num].w = diff(smooth_r, smooth_g, smooth_b, x, y, x+1, y-1);
	edges[num].w = diff(smoothedIm, x, y, x+1, y-1);
	num++;
      }
      */
    }
  }
  
  // Delete smoothed im
  for (int i = 0; i < depth; i++){
      delete smoothedIm[i];
  }

  // segment
  universe *u = segment_graph(width*height, num, edges, c);
  
  // post process small components
  for (int i = 0; i < num; i++) {
    int a = u->find(edges[i].a);
    int b = u->find(edges[i].b);
    if ((a != b) && ((u->size(a) < min_size) || (u->size(b) < min_size)))
      u->join(a, b);
  }
  delete [] edges;
  *num_ccs = u->num_sets();

  //image<rgb> *output = new image<rgb>(width, height);

  // pick random colors for each component
  double *colors = new double[width*height];
  for (int i = 0; i < width*height; i++)
    colors[i] = 0;
  
  int idx = 1;
  double* indexmap = new double[width * height];
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      int comp = u->find(y * width + x);
      if (!(colors[comp])){
          colors[comp] = idx;
          idx = idx + 1;
      }

      //imRef(output, x, y) = colors[comp];
      indexmap[x * height + y] = colors[comp];
    }
  }  
  //mexPrintf("indexmap 0: %f\n", indexmap[0]);
  //mexPrintf("indexmap 1: %f\n", indexmap[1]);

  delete [] colors;
  delete u;

  return indexmap;
}