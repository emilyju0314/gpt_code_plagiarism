int cont1(hpx::future<int> f)
{
    hpx::cout << "cont1 thread id: " << hpx::this_thread::get_id() << hpx::endl;
    hpx::cout << "Status code (HPX thread): " << f.get() << hpx::endl;
    hpx::cout << hpx::flush;
    return 1;
}