basic_endpoint(const char* path)
  {
    using namespace std; // For strlen.
    init(path, strlen(path));
  }