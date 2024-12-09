tuple<int16_t*, int> py_getCompClusters(int32_t* boxes, int boxCount, float eps, int min_samples)
{
  // Collect the raw boxes array into a vector of bboxes
  vector<ClusterBBox> vboxes = {};
  for (int i = 0; i < boxCount; i++)
  {
    int32_t* b = &boxes[8 * i];
    // Order here again as a reminder: left, top, right, top, right, bottom, left, bottom
    ClusterBBox box = {b[0], b[2], b[1], b[5], UNCLASSIFIED};
    vboxes.push_back(box);
  }
  DBSCAN scanner = DBSCAN(min_samples, eps, vboxes);
  scanner.run();
  vector<ClusterBBox> wLabels = scanner.getBoxes();

  // Collect labels into a raw format
  int n = wLabels.size();
  int16_t* labels = new int16_t[n];
  for (int i = 0; i < n; i++)
  {
    labels[i] = int16_t(wLabels[i].clusterID);
  }
  return make_tuple(labels, n);
}