TEST(AtlFreServerTests, RequireThat_Bite_CausesDogToBitePostman)
{
    const auto postman = wrl::Make<IPostmanMock>();
    EXPECT_CALL(*postman.Get(), OnBitten()).WillOnce(Invoke([]()
    {
        return S_OK;
    }));

    ComPtr<IDog> guardDog;
    HR(CoCreateInstance(__uuidof(GuardDog), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IDog), &guardDog));

    HR(guardDog->Bite(postman.Get()));
}