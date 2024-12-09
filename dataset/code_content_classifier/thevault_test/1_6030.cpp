bool sendHandKinematicsView(const YBVocab &vocab, YARPBabyBottle &bottle)
{
	bottle.writeVocab(vocab);
	cout << "Command requires now two double (azimuth, elevation)\n";
	YVector cmd;
	cmd.Resize(2);
	cin >> cmd(1);
	cin >> cmd(2);
		
	bottle.writeYVector(cmd);
	return true;
}