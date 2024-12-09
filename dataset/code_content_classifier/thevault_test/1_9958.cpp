StatusCode RootIoSvc::run()
 {
  StatusCode status = StatusCode::FAILURE ;
  MsgStream log(msgSvc(),name()) ;

    if ( 0 == m_appMgrUI )  return status; 

    // Check for an input merit tuple, and add its number of events to our
    // m_rootEvtMax
    if (m_rootTupleSvc) {
        void *treePtr;
        Long64_t entries = m_rootTupleSvc->getInputTreePtr(treePtr);
        if (entries > 0) setEvtMax(entries);
    }

    IProperty* propMgr=0;
    status = serviceLocator()->service("ApplicationMgr", propMgr );
    if( status.isFailure()) {
        log << MSG::ERROR << "Unable to locate PropertyManager Service" << endreq;
        return status;
    }

    // Pick up ApplicationMgr.EvtMax
    IntegerProperty evtMax("EvtMax",0);
    status = propMgr->getProperty( &evtMax );
    if (status.isFailure()) return status;
 
    // Determine if the min number of ROOT events is less than the
    // requested number of events in the jobOptions file
    IntegerProperty rootEvtMax("EvtMax", m_rootEvtMax);
    if ( (static_cast<int>(rootEvtMax-m_startIndex) < evtMax) || (evtMax==0) ) {
       evtMax = rootEvtMax - m_startIndex;
       setProperty(evtMax);
    } else setProperty(evtMax);

    m_evtMax = evtMax;

    // now find the top alg so we can monitor its error count
    IAlgManager* theAlgMgr =0 ;
    status = serviceLocator( )->getService( "ApplicationMgr",
        IAlgManager::interfaceID(),
        (IInterface*&)theAlgMgr );
    IAlgorithm* theIAlg;
    Algorithm*  theAlgorithm=0;
    IntegerProperty errorProperty("ErrorCount",0);
    
    status = theAlgMgr->getAlgorithm( "Top", theIAlg );
    if ( status.isSuccess( ) ) {
        try{
            theAlgorithm = dynamic_cast<Algorithm*>(theIAlg);
        } catch(...){
            status = StatusCode::FAILURE;
        }
    }
    if ( status.isFailure( ) ) {
        log << MSG::WARNING << "Could not find algorithm 'Top'; will not monitor errors" << endreq;
    }
    
    
    // loop over the events

    long long eventNumber= 0;
    double currentTime=m_startTime;
    
    { bool noend=true;
    log << MSG::INFO << "Runable interface starting event loop as :" ; 
    if( m_evtMax>0)  { log << " MaxEvt = " << m_evtMax; noend=false;  }
    if( m_endTime>0) { log << " EndTime= " << m_endTime; noend=false; }
    log << endreq;
    
    if(noend) { 
        log << MSG::WARNING << "No valid end condition specified: will not "
            << "process any events! MaxEvt = " << m_evtMax << endreq; 
    }
    }


     // Check for ROOT errors once before event loop in case there are 	 
     // errors to report 	 
     if ( (m_rootFileMessageHandler->getError()) || 	 
          (m_rootFileMessageHandler->getSysError()) || 	 
          (m_rootFileMessageHandler->getFatal()) ) { 	 
         m_rootFileMessageHandler->Print(); 	 
         if (m_abortOnRootError) { 	 
             // Bailing out and returning error code 	 
             log << MSG::ERROR << "Terminating due to ROOT error" << endreq; 	
             exit(-1); 	 
 	  } 	       
          m_rootFileMessageHandler->resetFlags();
     }


    // Not yet using time as a control on the event loop for ROOT
    while( m_evtMax>0 && eventNumber < m_evtMax
        || m_endTime>0 && currentTime< m_endTime ) {
        
        loopStatus( eventNumber, currentTime, log);

        status =  m_appMgrUI->nextEvent(1); // currently, always success
        
        // the single event may have created a failure. 
        // Check the ErrorCount propery of the Top alg.
        if( theAlgorithm !=0) theAlgorithm->getProperty(&errorProperty);
        if( status.isFailure() || errorProperty.value() > 0){
            status = StatusCode::FAILURE;
        }
        
        if( status.isFailure()) break;
        //if(flux!=0){
         //   currentTime = flux->gpsTime();
       // }


        // Check for ROOT errors
        if ( (m_rootFileMessageHandler->getError()) || 
             (m_rootFileMessageHandler->getSysError()) ||
             (m_rootFileMessageHandler->getFatal()) ) {
             m_rootFileMessageHandler->Print();
             if (m_abortOnRootError) {
                 // Bailing out and returning error code
                 log << MSG::ERROR << "Terminating due to ROOT error" << endreq;
                 exit(-1);
             }
             m_rootFileMessageHandler->resetFlags();
         }
   
        eventNumber++;
    }
    if( status.isFailure()){
        log << MSG::ERROR << "Terminating RootIoSvc loop due to error" << endreq;
        
    }else if( m_endTime>0 && currentTime >= m_endTime ) {
        log << MSG::INFO << "Loop terminated by time " << endreq;
    }else {
        log << MSG::INFO << "Processing loop terminated by event count" << endreq;
    }
    m_rootFileMessageHandler->Print();
    return status;
}