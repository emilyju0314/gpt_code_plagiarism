TEST(AtlHenTests, RequireThat_CoCreateInstance_CreatesAtlHen_WhenCalledWithHensClassId)
{
    CComPtr<IHen> hen;
    HR(CoCreateInstance(CLSID_AtlHen, nullptr, CLSCTX_INPROC_SERVER, IID_IHen, reinterpret_cast<void**>(&hen)));
    EXPECT_NE(hen, nullptr);
}