int EvalAllWindows(const Mat& image,
                   const HogBlockCache& cache,
                   const Size& subWinSize,
                   const HogSVM& svm) {
  int nWindows = 0;

  int maxY = image.rows - FLAGS_winH;
  int maxX = image.cols - FLAGS_winW;
  Size blockSize(FLAGS_min_block_size, FLAGS_min_block_size);
  Size blockStride(FLAGS_block_stride, FLAGS_block_stride);
  for (float y = 0; y < maxY; y+= FLAGS_win_stride) {
    for (float x = 0; x < maxX; x += FLAGS_win_stride) {
      Rect subWin(round(x + 1.0*0),
                  round(y + 1.0*0),
                  round(subWinSize.width*1.0),
                  round(subWinSize.height*1.0));
                        
      HogBlockIterator blockIter =
        HogBlockIterator(subWin, &cache, subWinSize,
                         blockSize, blockStride);

      svm.predict<float>(&blockIter);

      ++nWindows;
    }
  }
  return nWindows;
}