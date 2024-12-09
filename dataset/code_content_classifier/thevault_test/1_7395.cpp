Command Path::new_command(int left, int right){
  Command command;
  command.left = left;
  command.right = right;

  stringstream s;
  s << "(" << left << "," << right << ")";
  command.toString = s.str();

  return command;
}