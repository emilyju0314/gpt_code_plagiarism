void declearType_Stag_Detector(py::module &m) {
  py::class_<Stag>(m, "Detector")
      .def(py::init<>())
      .def(py::init<int, int, bool>(), "libraryHD"_a, "errorCorrection"_a,
           "inKeepLogs"_a)
      .def("detect", &Stag::detectMarkers, "inImage"_a)
      .def("log2File", &Stag::logResults, "path"_a)
      .def("getContours", &Stag::getContours)
      .def("getIds", &Stag::getIds);
}