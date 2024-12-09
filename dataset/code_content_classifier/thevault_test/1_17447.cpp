void            XPMPRegisterPlaneNotifierFunc(XPMPPlaneNotifier_f       inFunc,
                                              void *                    inRefcon)
{
    // Avoid duplicate entries
    XPMPPlaneNotifierTy observer (inFunc, inRefcon);
    if (std::find(glob.listObservers.begin(),
                  glob.listObservers.end(),
                  observer) == glob.listObservers.end()) {
        glob.listObservers.emplace_back(std::move(observer));
        LOG_MSG(logDEBUG, "%lu observers registered",
                (unsigned long)glob.listObservers.size());
    }
}