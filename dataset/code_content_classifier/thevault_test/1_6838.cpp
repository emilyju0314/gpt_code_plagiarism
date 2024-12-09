EWPolicy::EWPolicy() : Policy() {
  // Initialize detectors
  ewB = cewB = NULL;
  ewP = cewP = NULL;
  
  // Initialize rate limitor
  rlP = rlB = NULL;

  max_p = max_b = 0;
  alarm = pre_alarm = 0;
  change = 0;
}