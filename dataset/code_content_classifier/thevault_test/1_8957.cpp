BOOST_FOREACH(InFieldPicsManager::Listener* l, listeners)
                    {
                        if (picture->completeFile.size() == 0)
                        {
                            l->onNewInFieldPicTaken(picture);
                        }
                        else
                        {
                            l->onInFieldPicReceived(picture);
                        }
                    }