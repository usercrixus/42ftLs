#include "parser.h"
#include "printManager.h"

int main(int argc, char **argv)
{
	initFlags();
	manageSetFlags(argc, argv);
	manageListDir(argc, argv);
	return 0;
}
