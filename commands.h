// Command strucure
typedef struct {
	char* name;
	rl_icpfunc_t* func;
	char *doc;
} COMMAND;

// Command functions
int com_test PARAMS((char*));
int com_exit PARAMS((char*));

com_test(arg)
	char* arg;
{
	if(*arg)
	{
		printf("%s\n", arg);
	} else {
		printf("%s\n", TESTCOMMANDTEXT);
	}
	return(0);
};

com_exit(arg)
	char* arg;
{
	exit(0);
}

// Commands array
COMMAND commands[] = {
	{ "test", com_test, "Test command!" },
	{ "exit", com_exit, "Exit the program."}
};


