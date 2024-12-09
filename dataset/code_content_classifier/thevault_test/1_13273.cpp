IN_PROC_BROWSER_TEST_F(ScrollbarTest, ScrollbarRegression) {
  base::string16 permission_string(base::ASCIIToUTF16(
      "Read and modify your data on *.facebook.com"));
  std::vector<base::string16> permissions;
  permissions.push_back(permission_string);
  this->SetPromptPermissions(permissions);
  std::vector<base::string16> details;
  details.push_back(base::string16());
  this->SetPromptDetails(details);
  ASSERT_FALSE(IsScrollbarVisible()) << "Scrollbar is visible";
}