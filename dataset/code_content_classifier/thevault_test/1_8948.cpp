void CarObjectOfInterestMarker::modifyPolygons()
                {
                    //std::cout << "IN void CarObjectOfInterestMarker::modifyPolygons()" << std::endl;

                    markerNode->setVisible(false);

                    // Clears the old polygons (will regenerate every thing from the car of interest)
                    clearPolygons();

                    int numPolygon = 1;
                    std::vector<eu_nifti_env::FunctionalArea>::const_iterator it_begin = coi.functionalAreas.begin();
                    std::vector<eu_nifti_env::FunctionalArea>::const_iterator it_end = coi.functionalAreas.end();
                    for (; it_begin != it_end; it_begin++)
                    {
                        const eu_nifti_env::FunctionalArea& funcArea = *it_begin;

                        std::stringstream polygonName;
                        polygonName << "Element UUID #" << ooi->element.uuid << " / " << funcArea.function << " / Polygon #" << numPolygon++;

                        //std::cout << "Creating func area: " << polygonName.str() << std::endl;

                        // Attaches the polygon to the marker node rather than the scene node like before.
                        try
                        {
                            const Ogre::ColourValue& color = eu::nifti::ocu::display::OgreObjectsCreator::getColor(ooi->element.uuid % 125);

                            Ogre::ManualObject* polygon = sceneMgr->createManualObject(polygonName.str());
                            OgreObjectsCreator::createOgreGroundPolygon(funcArea.area, polygon, color, DEFAULT_HEIGHT_FUNC_AREAS, markerNode);
                            //OgreObjectsCreator::createOgreGroundPolygon(funcArea.area, polygon, color, DEFAULT_HEIGHT_FUNC_AREAS);

                            polygons->insert(polygon);
                            markerNode->attachObject(polygon);
                            //sceneMgr->getRootSceneNode()->attachObject(polygon);
                        } catch (Ogre::Exception& ex)
                        {
                            std::cerr << "An Ogre exception has occured while : " << ex.getFullDescription().c_str() << std::endl;
                        }


                    }

                    markerNode->setVisible(true);

                    //std::cout << "OUT void CarObjectOfInterestMarker::modifyPolygons()" << std::endl;
                }