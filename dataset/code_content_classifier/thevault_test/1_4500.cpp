tuple<int*, int> py_getFASTextBoxes(uint8_t* image, vector<array<int, 6>> kps, int wLimit, int hLimit)
{
  vector<bbox> boxes = getCornersThreaded(image, kps, wLimit, hLimit);
  int* boxesArr = new int[boxes.size() * 5];
  for (int i = 0; i < boxes.size(); i++)
  {
    bbox box = boxes[i];
    int s = i * 5;
    boxesArr[s] = box.minx; // x
    boxesArr[s+1] = box.miny; // y
    boxesArr[s+2] = box.maxx - box.minx; // width
    boxesArr[s+3] = box.maxy - box.miny; // height
    boxesArr[s+4] = box.threshold; // threshold
  }
  return make_tuple(boxesArr, boxes.size());
}