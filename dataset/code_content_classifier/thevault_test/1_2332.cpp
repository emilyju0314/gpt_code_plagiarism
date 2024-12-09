escher::ray4 WorldSpaceCreateScreenPerpendicularRay(float x, float y) {
  return {
      .origin = {x, y, -1000, 1},
      .direction = {0, 0, 1000, 0},
  };
}