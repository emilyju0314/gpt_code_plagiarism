void CVPlotting::setPlotPoints(double time){
    //array to be set contains t, A, dA/dt, th, d(th)/dt, x, y
    //originally had as map but thought it was pointless. want python dict!
    //define points
    //add in definitions of A and th
    float A, dA, th, dth,Ox,Oy;
    dA = 0;
    dth = 0;
    float x = CVProcessing::points[0][0].x;
    float y = CVProcessing::points[0][0].y;
    //if an origin put points in otherwise set to zero
    //must catch divide by zero
    if (!CVProcessing::origin2f.empty()){
        Ox = CVProcessing::origin2f[0].x;
        Oy = CVProcessing::origin2f[0].y;
        A = CVPlotting::amp(x,y,Ox,Oy);
        th = CVPlotting::th(x,y,Ox,Oy);
    }
    else{
        Ox = 0.;
        Oy = 0.;
        A = 0.;
        th = 0.;
    }
    //set max/min values
    int size = CVPlotting::plotPoints.size();
    if (size==0){
        
        CVPlotting::maxPoints[0] = (float)time;
        CVPlotting::minPoints[0] = (float)time;
        
        CVPlotting::maxPoints[1] = x;
        CVPlotting::minPoints[1] = x;
        
        CVPlotting::maxPoints[2] = y;
        CVPlotting::minPoints[2] = y;
        
        CVPlotting::maxPoints[3] = A;
        CVPlotting::minPoints[3] = A;
        
        CVPlotting::maxPoints[4] = th;
        CVPlotting::minPoints[4] = th;
 
    }
    else{
        CVPlotting::maxPoints[0] = float(time)+CVPlotting::plotPoints[size-1][0];
        
        if (x>CVPlotting::maxPoints[1]){
            CVPlotting::maxPoints[1] = x;
        }
        if (x<CVPlotting::minPoints[1]){
            CVPlotting::minPoints[1] = x;
        }
        if (y>CVPlotting::maxPoints[2]){
            CVPlotting::maxPoints[2] = y;
        }
        if (y<CVPlotting::minPoints[2]){
            CVPlotting::minPoints[2] = y;
        }
        if (A>CVPlotting::maxPoints[3]){
            CVPlotting::maxPoints[3] = A;
        }
        if (A<CVPlotting::minPoints[3]){
            CVPlotting::minPoints[3] = A;
        }
        if (th>CVPlotting::maxPoints[5]){
            CVPlotting::maxPoints[5] = th;
        }
        if (th<CVPlotting::minPoints[5]){
            CVPlotting::minPoints[5] = th;
        }
        
        if (size >= 1){
            dA = CVPlotting::damp(A, CVPlotting::plotPoints[size-1][3], 1.);
            dth = CVPlotting::dth(th, CVPlotting::plotPoints[size-1][5], 1.);
            if(size == 1){
                //set max/min
                CVPlotting::maxPoints[4] = dA;
                CVPlotting::minPoints[4] = dA;
                CVPlotting::maxPoints[6] = dth;
                CVPlotting::minPoints[6] = dth;
            }
            else{
                if (dA>CVPlotting::maxPoints[4]){
                    CVPlotting::maxPoints[4] = dA;
                }
                if (dA<CVPlotting::minPoints[4]){
                    CVPlotting::minPoints[4] = dA;
                }
                if (dth>CVPlotting::maxPoints[6]){
                    CVPlotting::maxPoints[6] = dth;
                }
                if (dth<CVPlotting::minPoints[6]){
                    CVPlotting::minPoints[6] = dth;
                }
            }
        }
    }
    //using structure
    //float vals[] = {(float)size, x, y,A,dA,th,dth};
    CVPlotting::plotPoints.push_back({CVPlotting::maxPoints[0], x, y,A,dA,th,dth});
}