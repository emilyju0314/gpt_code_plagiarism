static void checkDefaultFlow(DRTable &DRTab, const TableEntry &ent) {
	u_int16_t flow;
	if (!DRTab.find(ent.sourceIP, ent.destinationIP, flow))
		return;
	if (flow == ent.flowId)
		DRTab.flush(ent.sourceIP, ent.destinationIP);
}