TEST(CreatingComObjects,
     obtaining_the_guid_of_the_server)
{

    // Sometimes you may not have access to the type of the COM server you want to create. For example,
    // the ManagedServer do not provide us with a C++ PetShop type, and we can't call __uuidof(PetShop).
    // In these cases we can use the textual guid or the progid of the COM server instead.

    {
        // If you know the GUID of the COM object, you can just use this to get the guid of the COM class
        // This is not so readable, and it is not obvious what type of object we are creating
        CLSID petShopClsid{};
        HR(CLSIDFromString(L"{5011c315-994d-49b4-b737-03a846f590a0}", &petShopClsid));

        ComPtr<IPetShop> petShop;
        HR(CoCreateInstance(petShopClsid, nullptr, CLSCTX_INPROC_SERVER, __uuidof(IPetShop), &petShop));
        EXPECT_NE(petShop, nullptr);
    }

    {
        // If you know the progid of the COM object, you can use this instead. It is more readable,
        // and gives you a better indication of the type you are creating.
        CLSID petShopClsid{};
        HR(CLSIDFromProgID(L"ManagedServer.PetShop.1", &petShopClsid));

        ComPtr<IPetShop> petShop;
        HR(CoCreateInstance(petShopClsid, nullptr, CLSCTX_INPROC_SERVER, __uuidof(IPetShop), &petShop));
        EXPECT_NE(petShop, nullptr);
    }
}