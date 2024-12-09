NAN_MODULE_INIT(InitAll) {
    NAN_EXPORT(target, AddBot);
    NAN_EXPORT(target, AddComputer);
    NAN_EXPORT(target, StartGame);
    NAN_EXPORT(target, GetGameStatus);
    NAN_EXPORT(target, Update);
    NAN_EXPORT(target, GetStats);
    NAN_EXPORT(target, GetUnits);
    NAN_EXPORT(target, GetUnitClasses);
	NAN_EXPORT(target, GetUnitInfo);
	NAN_EXPORT(target, GetResourceInfo);
    NAN_EXPORT(target, CommandUnit);
}