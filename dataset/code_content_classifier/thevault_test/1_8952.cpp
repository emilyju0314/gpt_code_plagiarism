LocationOfInterestMarker::LocationOfInterestMarker(eu_nifti_env::LocationOfInterest& loi, Ogre::SceneManager* sceneMgr)
                : loi(loi)
                , ogreObject(ogre_tools::Shape(ogre_tools::Shape::Cone, sceneMgr))
                , ogreEntity(ogreObject.getEntity())
                {
                    Ogre::Vector3 position(loi.point.x, loi.point.y, loi.point.z);

                    // Makes the marker appear a bit above the ground
                    position.z += HEIGHT_ABOVE_GROUND;

                    ogreObject.setScale(Ogre::Vector3(0.2, 0.3, 0.2)); // Creates a thin cone, 30 cm high
                    ogreObject.setPosition(position);
                    ogreObject.setOrientation(Ogre::Quaternion(sqrt(0.5), sqrt(0.5), 0, 0)); // Turns the cone at 90 deg (since Fuerte)
                    ogreObject.setColor(0.2, 0.6, 0.2, 1); // Green, opaque
                }