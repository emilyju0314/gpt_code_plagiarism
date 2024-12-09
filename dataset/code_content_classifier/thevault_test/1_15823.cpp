TEST(AtlFreServerTests, RequireThat_CoCreateInstance_CreatesGuardDog_WhenCalledWithGuardDogUid)
{
    ComPtr<IDog> dog;
    HR(CoCreateInstance(__uuidof(GuardDog), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IDog), &dog));
    EXPECT_NE(dog, nullptr); 
}