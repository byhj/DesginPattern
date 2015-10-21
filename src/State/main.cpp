#include "State.h"

int main()
{
	Context ctx;
	ctx.request();
	ctx.changeStateOperation();
	ctx.request();

	cin.get();

	return 0;
}