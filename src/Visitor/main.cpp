#include "Visitor.h"

int main()
{
	ConcreteVisitor visitor;
	ConcreteElementA elementA;
	ConcreteElementB elementB;

	ObjectStructure objectStructure;
	objectStructure.addElement(&elementA);
	objectStructure.addElement(&elementB);

	objectStructure.accept(visitor);

	return 0;
}