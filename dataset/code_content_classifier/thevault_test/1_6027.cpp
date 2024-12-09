bool sendArmJointCommand(const YBVocab &vocab, YARPBabyBottle &bottle)
{
	bottle.writeVocab(vocab);
	cout << "Arm command requires now " << __armJoints << " joint position (grad)\n";
	YVector cmd;
	cmd.Resize(__armJoints);
	for (int i = 0; i < __armJoints; i++)
	{
		cin >> cmd(i+1);
		cmd(i+1) = cmd(i+1)*degToRad;
	}

	bottle.writeYVector(cmd);
	return true;
}