#include"Interpreter.h"

int main()
{
	Context context("A*B+C");
	AExpression aExp;
	BExPression bExp;

	vector<AbstractExpression*> expresions{ &aExp, &bExp };
	for (auto &e : expresions)
		e->interpret(context);

	cout << context.getOutput() << endl;

	cin.get();

	return 0;
}