#include "Command.h"

int main()
{
	Receiver receiver;
	ConcreteCommand1 command1(receiver, "Command");
	ConcreteCommand2 command2(receiver, 1);

	Macro macro;
	macro.addCommand(&command1);
	macro.addCommand(&command2);

	Invoker invoker(macro);
	invoker.executeCommand();

	cin.get();

	return 0;
}