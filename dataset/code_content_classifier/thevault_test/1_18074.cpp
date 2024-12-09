void init(int _img_width, int _img_height, float _marker_size, float *_camera_params, int _size_reduce) {
		img_width = _img_width;
		img_height = _img_height;
		marker_size = _marker_size;
		size_reduce = _size_reduce;
		if (size_reduce < 1) size_reduce = 1;

		dict = aruco::getPredefinedDictionary(aruco::DICT_ARUCO_ORIGINAL);

		ids = new vector<int>();
		corners = new vector<vector<Point2f>>();
		corners_flat = new vector<float>();

		tvecs = new vector<Vec3d>();
		rvecs = new vector<Vec3d>();
		tvecs_flat = new vector<double>();
		rvecs_flat = new vector<double>();

		camera_matrix = new Mat();
		dist_coeffs = new Mat();

		double scale_ratio = 1.0 / size_reduce;
		camera_matrix->create(3, 3, CV_64F);
		camera_matrix->at<double>(0, 0) = _camera_params[0] * scale_ratio;
		camera_matrix->at<double>(0, 1) = 0.0;
		camera_matrix->at<double>(0, 2) = _camera_params[2] * scale_ratio;
		camera_matrix->at<double>(1, 0) = 0.0;
		camera_matrix->at<double>(1, 1) = _camera_params[1] * scale_ratio;
		camera_matrix->at<double>(1, 2) = _camera_params[3] * scale_ratio;
		camera_matrix->at<double>(2, 0) = 0.0;
		camera_matrix->at<double>(2, 1) = 0.0;
		camera_matrix->at<double>(2, 2) = 1.0;

		dist_coeffs->create(5, 1, CV_64F);
		dist_coeffs->at<double>(0, 0) = _camera_params[4];
		dist_coeffs->at<double>(0, 1) = _camera_params[5];
		dist_coeffs->at<double>(0, 2) = _camera_params[6];
		dist_coeffs->at<double>(0, 3) = _camera_params[7];
		dist_coeffs->at<double>(0, 4) = _camera_params[8];
	}