#include <iostream>
#include "scopes.h"

int main()
{
	variable a;
	a.name = "test";
	a.init = false;
	Scope global;
	global.consumeVar(a);
	variable b;
	b.name = "anotherVar";
	b.init = false;
	Scope inner(&global);
	inner.consumeVar(b);
	inner.dumpVars();	
}
