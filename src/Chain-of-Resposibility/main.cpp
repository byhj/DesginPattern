#include "Chain.h"

int main()
{
	Handler1 h1;
	Handler2 h2;
	Handler3 h3;
	h1.setNextChain(&h2);
	h2.setNextChain(&h3);

	Request req("Do task # 3212", RequestType::REG_HANDER3);
	h1.handle(req);

	cin.get();

	return 0;
}