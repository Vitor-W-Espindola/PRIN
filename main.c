#define PREFIX "prin>"
#define TESTCOMMANDTEXT "Test command!"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "commands.h"
#include "utils.h"

int main() {
	initialize_readline();	
	while(1) {
		char* line = readline(PREFIX);
		line = stripwhite(line);
		if(*line) {
			add_history(line);
		}
		execute_line(line);	
		free(line);
	}
	return 0;
}
