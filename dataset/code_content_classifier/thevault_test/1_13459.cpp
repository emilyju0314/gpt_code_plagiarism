void Resources::initDevs()
{
    clear();
    // checks and adds PCI-bus
    IDevPtr pci(new PCIBus(m_factory));
    addDev(pci);
}