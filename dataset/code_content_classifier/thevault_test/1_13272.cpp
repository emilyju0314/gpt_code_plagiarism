IN_PROC_BROWSER_TEST_F(ScrollbarTest, LongPromptScrollbar) {
  base::string16 permission_string(base::ASCIIToUTF16("Test"));
  std::vector<base::string16> permissions;
  std::vector<base::string16> details;
  for (int i = 0; i < 20; i++) {
    permissions.push_back(permission_string);
    details.push_back(base::string16());
  }
  this->SetPromptPermissions(permissions);
  this->SetPromptDetails(details);
  ASSERT_TRUE(IsScrollbarVisible()) << "Scrollbar is not visible";
}