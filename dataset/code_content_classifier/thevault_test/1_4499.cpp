tuple<int*, int> py_getFASTextKeypoints(uint8_t* image, int count, int scales, int threshold, bool includePositive, bool includeNegative)
{
  int* icollector = new int[FLAT_SIZE * 6]{0};
  multiScaleKps(image, icollector, DIM_SIZE, scales, threshold);
  vector<array<int, 6>> kps = getNMSKeypoints5x5(count, icollector, includePositive, includeNegative);
  int* kpsArr = new int[kps.size() * 5];
  for (int i = 0; i < kps.size(); i++)
  {
    array<int, 6> kp = kps[i];
    int s = i * 5;
    // Flip x and y to keep python API consistent
    // Contrast is dropped because NMS is done already in C++ side
    kpsArr[s] = kp[1]; // x
    kpsArr[s+1] = kp[0]; // y
    kpsArr[s+2] = kp[2]; // keypoint type (end = 1, bend = 2)
    kpsArr[s+3] = kp[3]; // keypoint lightness (positive = 1, negative = 2)
    kpsArr[s+4] = kp[5]; // diff for thresholding the CC
  }
  delete[] icollector;
  return make_tuple(kpsArr, kps.size());
}