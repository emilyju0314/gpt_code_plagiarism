double computeWeight(double& min, double& max, double& value)
    {
      double interval_length = (max - min);
      return (value - min) / interval_length;
    }