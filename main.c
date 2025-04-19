#include <ftx_engine.h>

int	main(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;
	ftx_init(FTX_DEFAULT_TITLE, FTX_DEFAULT_WIDTH, FTX_DEFAULT_HEIGHT);
	ftx_exec();
	ftx_clear();
	return (0);
}
