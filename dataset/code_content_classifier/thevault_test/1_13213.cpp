int libioevent_startup(const Model& model) {
    ME* engines = model.subelementAt("engines");

    if(engines) {
        std::cout << "libIOEvent : engines found."<<std::endl;
        std::cout << "libIOEvent : engiens count: " << engines->subelementCount() << std::endl;
        for(unsigned int i = 0;i < engines->subelementCount();i ++) {
            ModelElement* e = engines->subelementAt(i);
            std::cout << "libIOEvent : engine - " << i << ":" << std::endl;
            e->echo(0);
            if(e) {
                const char* s = "path";
                char* path;
                //std::cout <<  "e->subelementAt(s)->echo : " << std::endl;
                e->subelementAt(s)->echo(0);
                e->subelementAt(s)->as(&path);
                //std::cout << "libIOEvent: moudle path - "; printf("%s",path); std::cout << std::endl;
                Module* m = new Module(path);
                ModuleInterface* interface = m->interface();
                /*
                if(interface) {
                    IOEngine* engine = static_cast<IOEngine*>(interface->createObject("engine"));
                }
                
                Module* module = new Module("/usr/local/lib/IOEngineLWS.so");

                ModuleInterface* interface = module->interface();
                */
                if(interface) {
                    std::cout << "libIOEvent : IOEngineLWS - Interface loaded." << std::endl;

                    if(interface->containClass("IOEngineLWS")){
                        std::cout << "libIOEvent : IOEngineLWS - Class : IOEngineLWS Exists." << std::endl;
                    } else {
                        std::cout << "libIOEvent : IOEngineLWS - Class : IOEngineLWS NOT Exists." << std::endl;
                    }

                    IOEngine* engine = static_cast<IOEngine*>(interface->createObject("engine"));
                    if(engine) {
                        std::cout << "libIOEvent : IOEngineLWS - IOEngine created." << std::endl;
                        Model em(ModelElement::MET_MAP);
                        ME es("IOET_UDP");
                        em.insertSubelement(&es,"type");
                        IOEndpoint* p = engine->createEndpoint(em);
                        if(p) { p->boot(); } else printf("NO ENDPOINT CREATED. \n");
                        //delete engine;
                    } else {
                        std::cout << "Module : IOEngineLWS - IOEngine create failed." << std::endl;
                    }
                }
            }   
        }
    } else {
      std::cout << "IOEvent : no engine found." << std::endl;
    }
    return 0;
}