static NetworkType NonLinearity(char func) {
  switch (func) {
    case 's':
      return NT_LOGISTIC;
    case 't':
      return NT_TANH;
    case 'r':
      return NT_RELU;
    case 'l':
      return NT_LINEAR;
    case 'm':
      return NT_SOFTMAX;
    case 'p':
      return NT_POSCLIP;
    case 'n':
      return NT_SYMCLIP;
    default:
      return NT_NONE;
  }
}