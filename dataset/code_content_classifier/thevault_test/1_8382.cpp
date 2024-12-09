void testJSONDebug_JSON_ASSERT::testFail(void){
	#if defined JSON_DEBUG
		#ifndef JSON_STDERROR
			JSON_ASSERT(1 == 0, fail_consta);
			assertEquals(last, fail_consta);  //make sure the callback was actually called
		#endif
	#endif
}