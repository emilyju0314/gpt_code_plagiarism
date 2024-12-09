bool sendHeadJointCommand(const YBVocab &vocab, YARPBabyBottle &bottle)
{
	bottle.writeVocab(vocab);
	cout << "Head command requires now " << __headJoints << " joint position (grad)\n";
	YVector cmd;
	cmd.Resize(__headJoints);
	for (int i = 0; i < __headJoints; i++)
	{
		cin >> cmd(i+1);
		cmd(i+1) = cmd(i+1)*degToRad;
	}

	bottle.writeYVector(cmd);
	return true;
}