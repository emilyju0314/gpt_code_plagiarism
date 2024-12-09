void FgNetDataPort::OnRead(void)
{
	///printf("Accesing OnRead\n");
	Read ();
	m_bottle = Content();
	m_bottle.rewind();
	m_bottle.readInt((int *)&m_bright);
	m_bottle.readInt((int *)&m_hue);
	m_bottle.readInt((int *)&m_contrast);
	m_bottle.readInt((int *)&m_satu);
	m_bottle.readInt((int *)&m_satv);
	m_bottle.readInt((int *)&m_lnotch);
	m_bottle.readInt((int *)&m_ldec);
	m_bottle.readInt((int *)&m_peak);
	m_bottle.readInt((int *)&m_cagc);
	m_bottle.readInt((int *)&m_ckill);
	m_bottle.readInt((int *)&m_range);
	m_bottle.readInt((int *)&m_ysleep);
	m_bottle.readInt((int *)&m_csleep);
	m_bottle.readInt((int *)&m_crush);
	m_bottle.readInt((int *)&m_gamma);
	m_bottle.readInt((int *)&m_dithf);

	///m_bottle.display();

	m_gb->setBright((unsigned int)m_bright);
	m_gb->setHue((unsigned int)m_hue);
	m_gb->setContrast((unsigned int)m_contrast);
	m_gb->setSatU((unsigned int)m_satu);
	m_gb->setSatV((unsigned int)m_satv);
	m_gb->setLNotch(m_lnotch);
	m_gb->setLDec(m_ldec);
	m_gb->setPeak(m_peak);
	m_gb->setCagc(m_cagc);
	m_gb->setCkill(m_ckill);
	m_gb->setRange(m_range);
	m_gb->setYsleep(m_ysleep);
	m_gb->setCsleep(m_csleep);
	m_gb->setCrush(m_crush);
	m_gb->setGamma(m_gamma);
	m_gb->setDithFrame(m_dithf);
}