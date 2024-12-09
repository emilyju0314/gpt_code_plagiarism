void
BusTopology::ExportGraph()
{
	GraphHelper* gh = GraphHelper::Get();
	gh->exportToFile();
}