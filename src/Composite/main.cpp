#include "Composite.h"

void PrintComp(Component &comp)
{
	comp.Print();
	cout << endl;
}

int main()
{
	//unix directory structure
	Composite root("/");
	Composite usr("usr");
	Composite home("home");
	Composite dev("dev");
	Composite user("user");
	Leaf file("file.txt");

	user.AddElement(&file);
	home.AddElement(&user);
	
	root.AddElement(&usr);
	root.AddElement(&dev);
	root.AddElement(&home);

//Composition of objects and object are treating in the same way
	PrintComp(root);
	PrintComp(file);

	cin.get();

	return 0;

}