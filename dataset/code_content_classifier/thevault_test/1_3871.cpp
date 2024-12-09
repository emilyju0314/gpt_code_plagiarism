static void interrupt(int)
{
    std::cout << "Received interrupt signal." << std::endl;
    exit(0);
}