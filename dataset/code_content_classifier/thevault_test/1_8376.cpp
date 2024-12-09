void UKF::CalculateNIS(const MeasurementPackage &measurement, const VectorXd &z_pred, const MatrixXd &S) {

  // actual calculation
  VectorXd residual = measurement.raw_measurements_ - z_pred;
  float e = residual.transpose() * S.inverse() * residual;

  // putting the result into a corresponding file + logging
  if ( debug_mode_ ) {

    const std::string sensor_type = ( measurement.sensor_type_ == MeasurementPackage::RADAR ? "Radar" : "Lidar" );

    // helper variables for string manipulation
    char buffer[10];
    std::stringstream content;
    std::stringstream filename;

    // assembling filename. It will look something like this: "../data/Lidar_NIS_values_2.1_0.4.txt"
    filename << nis_filename_prefix_ << sensor_type << "_NIS_values_";
    sprintf(buffer, "%.1f", std_a_);
    filename << std::string(buffer) << "_";
    sprintf(buffer, "%.2f", std_yawdd_);
    filename << std::string(buffer) << nis_filename_suffix_ << ".txt";

    // preparing content
    content << e;

    // dumping the NIS value into the file
    ofstream nis_dump;
    nis_dump.open(filename.str().c_str(), ios_base::out | ios_base::app);
    nis_dump << content.str() << endl;
    nis_dump.close();

    // displaying info in the console
    std::stringstream message;
    message << sensor_type << " NIS: " << e;
    Log(message.str());
  }
}