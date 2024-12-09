static void read_matrices ()
{
    // Read the model view and projection matrices from this frame
    XPLMGetDatavf(drMatrixWrld,gMatrixWrld,0,16);
    XPLMGetDatavf(drMatrixProj,gMatrixProj,0,16);
    
    // Read the screen size (won't change often if at all...but could!)
    gScreenW = (float)XPLMGetDatai(drScreenWidth);
    gScreenH = (float)XPLMGetDatai(drScreenHeight);
    
    // Field of view
    gFOV = XPLMGetDataf(drFieldOfView);
}