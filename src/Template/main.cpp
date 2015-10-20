#include "Template.h"

void FrameworkFunc(AppFramework &app)
{
	app.TemplateMothod();
}

int main()
{
	App app;
	FrameworkFunc(app);

	cin.get();

	return 0;
}