void ApplyGreedyNonMaximalSuppression(vector<cv::Rect>* boxes,
                                      vector<double>* scores,
                                      double overlapThresh) {
  ROS_ASSERT(boxes);
  ROS_ASSERT(scores);
  ROS_ASSERT(boxes->size() == scores->size());

  // Start by putting the rectangles and scores together in a data
  // structure that we will sort.
  vector<BoxScorePair> sortingBox;
  for (unsigned int i = 0u; i < boxes->size(); ++i) {
    sortingBox.push_back(BoxScorePair((*scores)[i], (*boxes)[i]));
  }

  // Sorts into ascending order
  sort(sortingBox.begin(), sortingBox.end(), BoxScorePairLessThan());

  // Now reset the outputs since we'll fill them as we go
  boxes->clear();
  scores->clear();
  
  // Starting from the highest score, add all those entries that don't
  // overlap with an entry already being returned.
  for (vector<BoxScorePair>::const_reverse_iterator i = sortingBox.rbegin();
       i != sortingBox.rend(); ++i) {
    bool doesOverlap = false;
    for (vector<cv::Rect>::const_iterator j = boxes->begin();
         j != boxes->end(); ++j) {
      if (CalculateOverlap(i->second, *j) > overlapThresh) {
        doesOverlap = true;
        break;
      }
    }

    if (!doesOverlap) {
      boxes->push_back(i->second);
      scores->push_back(i->first);
    }
  }
}