[[cheerp::jsexport]][[cheerp::wasm]]
void otherFunc(void(*func)(int,int))
{
	(*func)(5, 7);
}