void UKF::ProcessMeasurement(MeasurementPackage meas_package) {

  //if ((meas_package.sensor_type_ == MeasurementPackage::RADAR && use_radar_) ||
      //(meas_package.sensor_type_ == MeasurementPackage::LASER && use_laser_)) {
        if(is_initialized_==false){
        

        


     // init timestamp
        time_us_ = meas_package.timestamp_;
  /**
  TODO:

  Complete this function! Make sure you switch between lidar and radar
  measurements.
  */
        if(meas_package.sensor_type_==MeasurementPackage::LASER && use_laser_){

   /**
    * Initialize state.
    * Note: I have initialized the state and covriance depending on sensor type 
    * 
  
  */
            x_(0) = meas_package.raw_measurements_(0);
            x_(1) = meas_package.raw_measurements_(1);
            if (fabs(x_(0)) < 0.0001 and fabs(x_(1)) < 0.0001){
              x_(0) = 0.0001;
              x_(1) = 0.0001;
              }
              x_<<meas_package.raw_measurements_[0],
                  meas_package.raw_measurements_[1],
                  0.1,
                  0.1,
                  0;
              P_<<0.08, 0, 0, 0, 0,
            0, 0.08, 0, 0, 0,
            0, 0, 24, 0, 0,
            0, 0, 0, 0.01, 0,
            0, 0, 0, 0, 0.01;
              
                 
              //cout<<"Laser Measurement"<<endl;
              //cout<<x_(0)<<'\n'<<x_(1);
              }
        else if(meas_package.sensor_type_==MeasurementPackage::RADAR && use_radar_){
          float rho= meas_package.raw_measurements_[0];
          float phi= meas_package.raw_measurements_[1];
          float rho_dot= meas_package.raw_measurements_[2];

          float px= rho*cos(phi);
          float py= rho*sin(phi);
   //float v= sqrt((rho_dot*cos(phi)*rho_dot*cos(phi)) +(rho_dot*sin(phi)*rho_dot*sin(phi)));
   //float yaw_m= atan2(py,px);
          //x_(0)=px;
          //x_(1)=py;
          x_<<    px,
                  py,
                  meas_package.raw_measurements_[2],
                  0,
                  0;
          P_<<0.1, 0, 0, 0, 0,
            0, 0.1, 0, 0, 0,
            0, 0, 20, 0, 0,
            0, 0, 0, 0.01, 0,
            0, 0, 0, 0, 0.01;
   //x_(2)=v;
   //x_(3)=yaw_m;

          if (fabs(x_(0)) < 0.0001 and fabs(x_(1)) < 0.0001)
          {
              x_(0) = 0.0001;
              x_(1) = 0.0001;
          }
        
        }
 is_initialized_=true;
 return;
        }
 float dt = (meas_package.timestamp_ - time_us_) / 1000000.0;	//dt - expressed in seconds
 time_us_ = meas_package.timestamp_;

    Prediction(dt);

    /*****************************************************************************
    *  Update
    ****************************************************************************/

    if (meas_package.sensor_type_ == MeasurementPackage::LASER) {
      UpdateLidar(meas_package);
    }
    else if (meas_package.sensor_type_ == MeasurementPackage::RADAR) {
      UpdateRadar(meas_package);
    }
      //}

    // print the output
  //cout << "x_ = " << x_ << endl;
  //cout << "P_ = " << P_ << endl;
  //cout << "x_ = " << NIS_Lidar_ << endl;
  //cout << "P_ = " << NIS_radar_ << endl;
}