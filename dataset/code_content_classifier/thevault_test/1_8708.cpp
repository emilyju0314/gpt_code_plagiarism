int runopencvex()
{
  string imagefile = setpath + "FingerData/coin/image01.png";
  string outfile = setpath + "FingerData/coin/gsimage.png";
  string memcpyoutfile = setpath + "FingerData/coin/gsimagememcpy.png";

  cout << "Running with data from" << imagefile << endl;

  // Load images from scan into opencv
  cv::Mat inimage, matimage;
  inimage = cv::imread(imagefile);

  if (inimage.empty()) {                                   
    cout << "could not open " << imagefile << endl;
    return 1;
  }
  
  // First example, using memcpy to copy a cv::Mat BGR to a gelsight BGR image
  // Allocate the gelsight image
  const auto bgr8 = gs::Bgr8(0,0,0);
  gs::ImageBgr8 gscopy(gs::SizeI(inimage.cols, inimage.rows), bgr8);
  // copy the image and write it out 
  memcpy(gscopy.ptr(0), &inimage.data[0], inimage.cols*inimage.rows*3);
  gs::util::WritePng(memcpyoutfile, gscopy);

  // Second example convert cv::Mat to gray image and write it out to a png file
  cv::cvtColor(inimage, matimage, cv::COLOR_BGR2GRAY); 

  // Third example, brute force copy pixel by pixel
  // Split the cv::Mat image into BGR channels
  std::vector<cv::Mat> channels;
  cv::split(inimage, channels);
  cv::Mat imageB = channels[0];
  cv::Mat imageG = channels[1];
  cv::Mat imageR = channels[2];

  //cv::imshow("Input image", matimage);
  //cv::waitKey(0);

  // Convert to gs::image
  auto xdim = matimage.cols;
  auto ydim = matimage.rows;

  // gsimage is a floating point image just for example
  // bgrim is the converted cv::Mat BGR image
  // this is the data we need to create the surface 
  gs::ImageF gsimage(gs::SizeI(xdim,ydim),0.0);
  gs::ImageBgr8 bgrim(gs::SizeI(xdim,ydim), bgr8);

  for (int y = 0; y < ydim; y++)
  {
    uchar *mimptr = inimage.ptr<uchar>(y);

    for (int x = 0; x < xdim; x++)
    {
      float pix = matimage.at<uchar>(y,x) / 255.;
      gsimage.setpel(y, x, pix);

      gs::Bgr8 bgrpix = gs::Bgr8(imageB.at<uchar>(y,x), imageG.at<uchar>(y,x), imageR.at<uchar>(y,x));
      bgrim.setpel(y, x, bgrpix);
    }
  }

  cout << "Write output png file" << outfile << endl;
  gs::util::WritePng(outfile, gsimage);
  
  // run the calibration
   auto modelfile = setpath + "FingerData/finger-model.yaml";
   cout << "Loading saved calibration data: " << modelfile << endl;

  // Load PhotometricStereo algorithm from settings file
  // Run pstereo algorithm on scan
  auto pstereo = gs::LoadPhotometricStereo(modelfile);

  gs::RectI croproi(300,500,1000,1250);

  // Do surface normal reconstruction
  // This is where the converted cv::Mat BGR image is used
  // We copied it into bgrim but we could have also used gscopy
  auto nrm = pstereo->linearNormalMap(bgrim, croproi);

  // Integrate normals into heightmap
  cout << "Integrating surface normals..." << endl;
  auto poisson = gs::CreateIntegrator(gs::Version());
  auto heightmap = poisson->integrateNormalMap(nrm, pstereo->resolution());

  // Save surface as TMD
  string out1 = setpath + "FingerData/coin/output.tmd";
  cout << "Saving heightmap: " << out1 << endl;
  gs::util::WriteTMD(out1, heightmap, pstereo->resolution(), 0.0, 0.0);

  // Save normal map
  string out2 = setpath + "FingerData/coin/output_nrm.png";
  cout << "Saving normal map: " << out2 << endl;
  gs::util::WriteNormalMap(out2, nrm, 16);

  return 0;
}