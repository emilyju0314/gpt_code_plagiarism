void GlobVars::ReadVersions ()
{
    XPLMHostApplicationID hostID = -1;
    XPLMGetVersions(&glob.verXPlane, &glob.verXPLM, &hostID);
    
    // Also read if we are using Vulkan/Metal
    XPLMDataRef drUsingModernDriver = XPLMFindDataRef("sim/graphics/view/using_modern_driver");
    if (drUsingModernDriver)            // dataRef not defined before 11.50
        bXPUsingModernGraphicsDriver = XPLMGetDatai(drUsingModernDriver) != 0;
    else
        bXPUsingModernGraphicsDriver = false;
}