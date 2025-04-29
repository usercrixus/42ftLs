#include "printer.h"
#include "parser.h"

int main(int argc, char **argv)
{
	initFlags();
	manageSetFlags(argc, argv);
	manageListDir(argc, argv);
	return 0;
}
