void util::ExtractedDeviceState::deserialize(std::istream &in) {
	hydrazine::json::Parser parser;
	hydrazine::json::Object *stateObject = 0;

	{
		stateObject = parser.parse_object(in);
		hydrazine::json::Visitor object(stateObject);
		
		application.deserialize(object["application"]);
		launch.deserialize(object["kernelLaunch"]);
		
		hydrazine::json::Visitor allocationsArray(object["allocations"]);
		for (hydrazine::json::Array::const_iterator
			alloc_it = allocationsArray.begin_array();
			alloc_it != allocationsArray.end_array(); ++alloc_it) {
			
			MemoryAllocation* allocation = new MemoryAllocation;
			allocation->deserialize(hydrazine::json::Visitor(*alloc_it));
			globalAllocations[allocation->devicePointer] = allocation;
		}
		
		hydrazine::json::Visitor globalsArray(object["global_allocations"]);
		for (hydrazine::json::Array::const_iterator
			alloc_it = globalsArray.begin_array();
			alloc_it != globalsArray.end_array(); ++alloc_it) {
			
			GlobalAllocation* allocation = new GlobalAllocation;
			allocation->deserialize(hydrazine::json::Visitor(*alloc_it));
			globalVariables[allocation->key()] = allocation;
		}
		
		hydrazine::json::Visitor postAllocationsArray(
			object["post_launch_allocations"]);
		for (hydrazine::json::Array::const_iterator
			alloc_it = postAllocationsArray.begin_array();
			alloc_it != postAllocationsArray.end_array(); ++alloc_it) {
			
			MemoryAllocation* allocation = new MemoryAllocation;
			allocation->deserialize(hydrazine::json::Visitor(*alloc_it));
			postLaunchGlobalAllocations[allocation->devicePointer] = allocation;
		}
		
		hydrazine::json::Visitor postGlobalsArray(
			object["post_launch_global_allocations"]);
		for (hydrazine::json::Array::const_iterator
			alloc_it = postGlobalsArray.begin_array();
			alloc_it != postGlobalsArray.end_array(); ++alloc_it) {
			
			GlobalAllocation* allocation = new GlobalAllocation;
			allocation->deserialize(hydrazine::json::Visitor(*alloc_it));
			postLaunchGlobalVariables[allocation->key()] = allocation;
		}

		hydrazine::json::Visitor modulesArray(object["modules"]);
		for (hydrazine::json::Array::const_iterator
			mod_it = modulesArray.begin_array();
			mod_it != modulesArray.end_array(); ++mod_it) {
			
			Module* module = new Module;
			module->deserialize(hydrazine::json::Visitor(*mod_it));
			modules[module->name] = module;
		}
	}
	
	if (stateObject) delete stateObject;
}