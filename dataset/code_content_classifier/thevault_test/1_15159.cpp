void no::df::testfunc(no::Model& model, py::object& df, const std::string& colname)
{
  // .values? pd.Series -> np.array?
  py::array arr = df.attr(colname.c_str()); //.request();

  //no::log(arr.dtype());
  py::buffer_info buf = arr.request();

  py::ssize_t n = buf.shape[0];


  if (arr.dtype().is(py::dtype::of<int64_t>()))
  {
    dump(static_cast<int64_t*>(buf.ptr), n);
  }
  else if (arr.dtype().is(py::dtype::of<double>()))
  {
    dump(static_cast<double*>(buf.ptr), n);
  }
  else if (arr.dtype().is(py::dtype::of<bool>()))
  {
    dump(static_cast<bool*>(buf.ptr), n);
  }
  // else if (arr.dtype() == "object")
  // {
  //   py::str* p = static_cast<py::str*>(buf.ptr);
  // }
  // else if (arr.dtype() == py::object)
  // {
  //   py::object* p = static_cast<py::object*>(buf.ptr);
  //   for (py::ssize_t i = 0; i < n; ++i, ++p)
  //   {
  //     no::log(*p);
  //   }
  // }
  else
  {
    throw py::type_error("unsupported dtype '%%' in column '%%'"s % /*arr.dtype().cast<std::string>() %*/ colname);
  }
}