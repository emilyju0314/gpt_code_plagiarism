bool Object::Update( bool buttonpressed )
{
    bool retval = false;

    //If mass == 0 the object is anchored and does not need to be updated
    if( mass > 0 ){

        //Sum of acting forces
        float totalForcex = 0.0;
        //float totalForcey = 0.0;
        float totalForcey = 0.0;

        //Calculate time (in seconds) since last update
        float newTime = float(SDL_GetTicks()) / 1000;
        float deltaTime = newTime - oldTime;
        //debug out cout << "newTime: " << newTime << ", deltaTime: " << deltaTime << endl;

        //Dunno what these are for..
        //float oldxVel = xVel;
        //float oldyVel = yVel;

        //Store coords in case of collision
        float tempx = x;
        float tempy = y;

        //Create/Set Collision variables
        bool xcol = false;
        bool ycol = false;

        //Iterate through forces if there are any
        if( fApp.size() > 0 )
        {
            float magnitude = 0.0;
            float angle = 0.0;
            float radians = 0.0;
            int initTime = 0;
            int duration = 0;

            for( fAppIter = fApp.begin(); fAppIter != fApp.end(); fAppIter++ )
            {
                magnitude = (*fAppIter)->Magnitude();// * mass;
                angle = (*fAppIter)->Angle();
                radians = (angle * 3.14159265)/180;
                initTime = (*fAppIter)->InitTime();
                duration = (*fAppIter)->Duration();

                if( angle == 0 || angle == 360 ){
                    totalForcey += magnitude;
                }else if( angle == 90 ){
                    totalForcex += magnitude;
                }else if( angle == 180 ){
                    totalForcey -= magnitude;
                }else if( angle == 270 ){
                    totalForcex -= magnitude;
                }else if( angle > 0 && angle < 90 ){
                    totalForcex += ( sin(radians) * magnitude );
                    totalForcey += ( cos(radians) * magnitude );
                }else if( angle > 90 && angle < 180 ){
                    totalForcex += ( sin(radians) * magnitude );
                    totalForcey += ( cos(radians) * magnitude );
                }else if( angle > 180 && angle < 270 ){
                    totalForcex += ( sin(radians) * magnitude );
                    totalForcey += ( cos(radians) * magnitude );
                }else if( angle > 270 && angle < 360 ){
                    totalForcex += ( sin(radians) * magnitude );
                    totalForcey += ( cos(radians) * magnitude );
                }

                if( duration > 0 )
                {
                    if( (SDL_GetTicks() - initTime > duration) )
                    {
                        deadForces.push_back( fAppIter );
                    }
                }
            }
        }

        if( deadForces.size() > 0 )
        {
            for( deadForcesIter = deadForces.begin(); deadForcesIter != deadForces.end(); deadForcesIter++ )
            {
                fApp.erase( (*deadForcesIter) );
            }

            deadForces.clear();
        }

        if( !collision && (totalForcey != 0 || totalForcex != 0 || accelx != 0 || accely != 0) ){
            totalForcey += mass * -9.81;
        }else{
            if( collision ){
                retval = true;
            }
            x = 0;
            y = 0;
            xVel = 0;
            yVel = 0;
        }

        //Calculate frictional force
        //totalForcex += ( -1 * xVel / mass );
        //totalForcey += ( -1 * yVel / mass );
        //cout << "tFx" << totalForcex << " += ( -1 * " << xVel << " / mass );" << endl;
        //cout << "tFy" << totalForcey << " += ( -1 * " << yVel << " / mass );" << endl << endl;

        //Calculate horizontal acceleration after air resistance
        //if( xVel - air > 0 ){
        //    accelx = totalForcex / mass - air;
        //}else if( xVel + air < 0 ){
        //    accelx = totalForcex / mass + air;
        //}else{
            //xVel = 0;

        //float airResistancex = 0.96 * xVel;// * xVel;
        //float airResistancey = 0.96 * yVel;// * yVel;

            accelx = totalForcex / mass;// * deltaTime;
            //accelx += -1 * xVel / mass;
            //debug out cout << "accelx: " << accelx << " = " << deltaTime << " * " << totalForcex << " / " << mass << endl;

            //accelx = deltaTime * totalForcex / mass;
        //}

        //Calculate vertical acceleration after air resistance
        //if( yVel - air > 0 ){
        //    accely = totalForcey / mass - air;
        //}else if( yVel + air < 0 ){
        //    accely = totalForcey / mass + air;
        //}else{
            //yVel = 0;

            accely = totalForcey / mass;// * deltaTime;
            //accely += -1 * yVel / mass;
            //debug out cout << "accely: " << accely << " = " << deltaTime << " * " << totalForcey << " / " << mass << endl << endl;

            //accely = deltaTime * totalForcey / mass;
        //}

        //cout << "Accelx: " << accelx << endl;
        //cout << "Accely: " << accely << endl;

        //Update Velocities
        //xVel += accelx;
        xVel += accelx * deltaTime;
        //xVel += (accelx - airResistancex) * deltaTime;
        //yVel += accely;
        yVel += accely * deltaTime;
        //yVel += (accely - airResistancey) * deltaTime;

        //xVel = xVel * air;
        //yVel = yVel * air;

        /*if( xVel - air > 0 ){
            xVel = xVel - air;
        }else if( xVel + air < 0 ){
            xVel = xVel + air;
        }else{
            xVel = 0;
        }

        if( yVel - air > 0 ){
            yVel = yVel - air;
        }else if( yVel + air < 0 ){
            yVel = yVel + air;
        }else{
            yVel = 0;
        }*/

        //debug out cout << "xVel: " << xVel << " = xVel + " << accelx << endl;
        //debug out cout << "yVel: " << yVel << " = yVel + " << accely << endl << endl;

        /*

         // DETERMINE THE NEW VELOCITY FOR THE PARTICLE
        target->v.x = source->v.x + (DeltaTime * source->f.x * source->oneOverM);
        target->v.y = source->v.y + (DeltaTime * source->f.y * source->oneOverM);
        target->v.z = source->v.z + (DeltaTime * source->f.z * source->oneOverM);

        // SET THE NEW POSITION
        target->pos.x = source->pos.x + (DeltaTime * source->v.x);
        target->pos.y = source->pos.y + (DeltaTime * source->v.y);
        target->pos.z = source->pos.z + (DeltaTime * source->v.z);

        */

        if( buttonpressed == false ){
        //Zero the velocity if too small to matter
        //otherwise update the position
        //if( xVel < -0.01 || xVel < 0.01 ){
            //Divide by meters / pixels
            //x += xVel / 5;
            //x += xVel / 500;

            //x += xVel;

            x += (xVel * deltaTime) / 3;

            //s0 + v0*t + 0.5*a*t^2
            //x += (xVel * deltaTime) + (0.5 * accelx * (deltaTime * deltaTime));
            //debug out cout << "x: " << x << " = x + (" << xVel << " * " << deltaTime << ") / 5" << endl;
        //}else{
        //    xVel = 0;
        //}

        //Zero the velocity if too small to matter
        //otherwise update the position
        //if( yVel < -0.01 || yVel < 0.01 ){
            //Divide by meters / pixels
            //y += yVel / 5;
            //y += yVel / 500;

            //y += yVel;

            y += (yVel * deltaTime) / 3;

            //s0 + v0*t + 0.5*a*t^2
            //y += (yVel * deltaTime) + (0.5 * accely * (deltaTime * deltaTime));
            //debug out cout << "y: " << y << " = y + (" << yVel << " * " << deltaTime << ") / 5" << endl << endl;
        //}else{
        //    yVel = 0;
        //}
        }else{
            xVel = 0;
            yVel = 0;
        }

        //cout << "x: " << x << endl << endl;
        //cout << "y: " << y << endl;

        //Reset Collision Variable (For colored drawing)
        collision = false;

        //Set the vertices
        for( verticesIter = vertices.begin(); verticesIter != vertices.end(); verticesIter++ )
        {
            bool tmpxcol = false;
            bool tmpycol = false;
            bool equal = false;

            //Check edge of screen collision x
            if( xcol == false ){
                if( x + (*verticesIter)->X() < -1.0 ){
                    tmpxcol = true;
                    //x -= (x + (*verticesIter)->X()) - (-1.0);
                    x = (-1.0) - (*verticesIter)->X();
                    //y = tempy;
                }else if( x + (*verticesIter)->X() > 1.0 ){
                    tmpxcol = true;
                    //x -= (x + (*verticesIter)->X()) - (1.0);
                    x = ( 1.0) - (*verticesIter)->X();
                    //y = tempy;
                }
            }

            //Check edge of screen collision y
            if( ycol == false ){
                if( y + (*verticesIter)->Y() < -1.0 ){
                    tmpycol = true;
                    //y -= (y + (*verticesIter)->Y()) - (-1.0);
                    y = (-1.0) - (*verticesIter)->Y();
                    //x = tempx;
                }else if( y + (*verticesIter)->Y() > 1.0 ){
                    tmpycol = true;
                    //y -= (y + (*verticesIter)->Y()) - (1.0);
                    y = ( 1.0) - (*verticesIter)->Y();
                    //x = tempx;
                }
            }

            //If collision reverse velocities and absorb some force
            if( (tmpxcol || tmpycol) && (!xcol || !ycol) ){
                if( tmpxcol && !xcol ){
                    //If velocity less than 1 m/s stop bouncing
                    if( xVel < -1.0 || xVel > 1.0 ){
                        if( mass > 2 ){
                            xVel = -1 * xVel * ((1 / mass) * 2);//0.65;
                            //debug out cout << "air friction x: " << -1 * xVel * ((1 / mass) * 2) << endl;
                        }else{
                            xVel = -1 * xVel * (0.75);
                            //debug out cout << "air friction x: " << -1 * xVel * (0.75) << endl << endl;
                        }
                        //xVel = -xVel;
                    }else{
                        xVel = 0;
                    }
                    if( !equal ){
                        x = tempx;
                    }
                    xcol = true;
                    collision = true;
                }
                if( tmpycol && !ycol ){
                    //If velocity less than 1 m/s stop bouncing
                    if( yVel < -1.0 || yVel > 1.0 ){
                        if( mass > 2 ){
                            yVel = -1 * yVel * ((1 / mass) * 2);//0.65;
                            //debug out cout << "air friction y: " << -1 * yVel * ((1 / mass) * 2) << endl;
                        }else{
                            yVel = -1 * yVel * (0.75);
                            //debug out cout << "air friction y: " << -1 * yVel * (0.75) << endl << endl;
                        }
                        //yVel = -yVel;
                    }else{
                        yVel = 0;
                    }
                    if( !equal ){
                        y = tempy;
                    }
                    ycol = true;
                    collision = true;
                }
            //}else{
            //    if( !xcol && !ycol ){
            //        collision = false;
            //    }
            }
        }

        oldTime = newTime;
    }

    return retval;
}