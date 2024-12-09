bool utils::isCommentLine(std::string line)
{
  line = utils::trimLeading(line);
  return line.substr(0, utils::COMMENT_SYMBOL.length()) == utils::COMMENT_SYMBOL;
}