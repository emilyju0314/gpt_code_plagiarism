string Process::Ram()
 { 
     long ramMB =0;
     ram_= LinuxParser::Ram(Pid());
     try
     {
        /* code */
       ramMB = std::stol(ram_)/1000;
     }
     catch(const std::exception& e)
     {
        std::cerr << e.what() << '\n';
        ramMB =0;
     }
     ram_ = std::to_string(ramMB) ;
     return (ram_); 
}