void testJSONDebug_JSON_ASSERT::testPass(void){
	#if defined JSON_DEBUG
		#ifndef JSON_STDERROR
			JSON_ASSERT(1 == 1, fail_consta);
			assertEquals(last, null_consta);  //make sure the callback was not called
		#endif
	#endif
}