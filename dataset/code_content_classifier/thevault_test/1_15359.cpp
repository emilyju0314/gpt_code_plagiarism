bool UserType::initializeFromMetaTypeDir(path metaTypeDir) {
    std::cout << "metaTypeDir is " << metaTypeDir << std::endl; 
    // traverse all set files in type directory
    // for each set file, invoke addSet to initialize PDBFile object and CircularInputBuffer
    if (exists(metaTypeDir)) {
        if (is_directory(metaTypeDir)) {
            vector<path> metaSetFiles;
            copy(
                directory_iterator(metaTypeDir), directory_iterator(), back_inserter(metaSetFiles));
            vector<path>::iterator iter;
            std::string path;
            std::string dirName;
            std::string name;
            SetID setId;
            for (iter = metaSetFiles.begin(); iter != metaSetFiles.end(); iter++) {
                if (is_regular_file(*iter)) {
                    // find a set
                    path = std::string(iter->c_str());
                    std::cout << "path to set file is " << path << std::endl;
                    dirName = path.substr(path.find_last_of('/') + 1, path.length() - 1);
                    // parse set name
                    name = dirName.substr(dirName.find('_') + 1, dirName.length() - 1);
                    // parse set id
                    setId = stoul(dirName.substr(0, dirName.find('_')));
                    std::cout << "set name is " << name << ", setId is " << setId << std::endl;
                    // check whether set exists
                    if (this->sets->find(setId) != this->sets->end()) {
                        this->logger->writeLn("UserType: set exists.");
                        return false;
                    }

                    std::cout << "create partitioned file instance" << std::endl;
                    // create PartitionedFile instance
                    PartitionedFilePtr partitionedFile = make_shared<PartitionedFile>(
                        this->nodeId, this->dbId, this->id, setId, path, this->logger);

                    std::cout << "build metadata from meta partition" << std::endl;
                    partitionedFile->buildMetaDataFromMetaPartition(nullptr);
                    std::cout << "initialize data files" << std::endl;
                    partitionedFile->initializeDataFiles();
                    std::cout << "open data" << std::endl;
                    partitionedFile->openData();
                    std::cout << "create set" << std::endl;
                    // create a Set instance from file
                    SetPtr set = make_shared<UserSet>(partitionedFile->getPageSize(),
                                                      logger,
                                                      this->shm,
                                                      nodeId,
                                                      dbId,
                                                      id,
                                                      setId,
                                                      name,
                                                      partitionedFile,
                                                      this->cache, JobData, LRU, Read, TryCache, Persistent);
                    // add buffer to map
                    if (set == 0) {
                        this->logger->error("Fatal Error: UserType: out of memory.");
                        exit(1);
                    }
                    this->sets->insert(pair<SetID, SetPtr>(setId, set));
                    this->numSets++;
                    this->logger->writeLn("UserType: set added.");
                }
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
    return true;
}