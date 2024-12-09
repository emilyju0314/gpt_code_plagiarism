void UTCTask::createFile(std::string fileName)
{
    std::ofstream outfile(fileName);
    outfile << "TEST TEXT" << std::endl;
    outfile.close();
}