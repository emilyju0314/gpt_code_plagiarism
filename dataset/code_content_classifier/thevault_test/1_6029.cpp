bool sendHandJointCommand(const YBVocab &vocab, YARPBabyBottle &bottle)
{
	bottle.writeVocab(vocab);
	cout << "Hand command requires now " << __handJoints << " joint position (grad)\n";
	YVector cmd;
	cmd.Resize(__handJoints);
	for (int i = 0; i < __handJoints; i++)
	{
		cin >> cmd(i+1);
		cmd(i+1) = cmd(i+1)*degToRad;
	}

	bottle.writeYVector(cmd);
	return true;
}