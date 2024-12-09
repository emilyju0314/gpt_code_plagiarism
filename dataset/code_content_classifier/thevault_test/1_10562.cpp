int OrientationIdToValue(const int &id) {
  switch (id) {
    case 0:
      return 0;
    case 1:
      return 270;
    case 2:
      return 180;
    case 3:
      return 90;
    default:
      return -1;
  }
}