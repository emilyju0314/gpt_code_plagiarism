std::string handle_user_ex(user_exception&)
{
 std::cout << "* caught user_exception; rewriting output" << '\n';

 return "I decided to return a valid result!";
}