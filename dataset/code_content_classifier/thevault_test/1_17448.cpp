void            XPMPUnregisterPlaneNotifierFunc(XPMPPlaneNotifier_f     inFunc,
                                                void *                  inRefcon)
{
    auto iter = std::find(glob.listObservers.begin(),
                          glob.listObservers.end(),
                          XPMPPlaneNotifierTy (inFunc, inRefcon));
    if (iter != glob.listObservers.cend()) {
        glob.listObservers.erase(iter);
        LOG_MSG(logDEBUG, "%lu observers registered",
                (unsigned long)glob.listObservers.size());
    }
}