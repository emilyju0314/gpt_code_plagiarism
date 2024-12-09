void Camera::readDriver(ifstream& driver){
    string line = "";
    while(getline(driver, line)){
        istringstream iss(line);
        string id = "";
        if (iss >> id){
            if(id[0] == '#') continue;
            else if(id == "eye"){
                
                /*
                 * Read the focal point.
                 */
                for(int i = 0; i < 3; i++){iss >> eye[i];}
            }
            else if(id == "look"){
                
                /*
                 * Read the look at point.
                 */
                for(int i = 0; i < 3; i++){iss >> look[i];}
            }
            else if(id == "up"){
                
                /*
                 * Read the up vector.
                 */
                for(int i = 0; i < 3; i++){iss >> up[i];}
            }
            else if(id == "d"){
                
                /*
                 * Read the focal length.
                 */
                iss >> d;
            }
            else if(id == "bounds"){
                
                /*
                 * Read the bounds of the image plane.
                 */
                for(int i = 0; i < 4; i++){iss >> bounds[i];}
            }
            else if(id == "res"){
                
                /*
                 * Read the resolution.
                 */
                for(int i = 0; i < 2; i++){iss >> res[i];}
            } else {continue;}
        } else {continue;}
    }
    driver.close(); 
}