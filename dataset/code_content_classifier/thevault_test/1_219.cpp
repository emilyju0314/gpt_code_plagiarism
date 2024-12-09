bool luaConf::getFloat(string varName, float &f)
{
	if (getDouble(varName, (double &)f)) {
		return true;
	} else {
		return false;
	}

}