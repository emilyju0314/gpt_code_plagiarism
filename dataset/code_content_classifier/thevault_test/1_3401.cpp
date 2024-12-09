int cont2(hpx::future<int> f)
{
    std::cout << "Status code (main thread): " << f.get() << std::endl;
    return 1;
}