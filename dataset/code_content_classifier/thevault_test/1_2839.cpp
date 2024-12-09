int DataManager::dataMain()
{
    Controller3D cont3;
    // float longest = 0, shortest = 99;
    bool first = true;
    while(true)
    {
        std::clock_t start;
        double duration;
        start = std::clock();

        cont3.CreateNewInformation();
        while(GUIData::getInstance()->configuring){
            cont3.configure();
        }

        cont3.ProccesPointcloud();
        cont3.DetectObjects(0);
        cont3.RepaintVisualizer();
        cont3.assignIdentification();
        cont3.CalculateSpeed();
        cont3.calculateDirection();
        cont3.pushUIData();

        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

        first = false;
        std::cout<<"Duration of inference with intake and delays: "<< duration << std::endl;
    }
    cout << "Exiting application..." << endl;
    return 1;
}