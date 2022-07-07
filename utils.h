COMMAND* find_command(name)
	char* name;
{
	register int i;
	for(i = 0; commands[i].name; i++)
	{
		if(strcmp(name, commands[i].name) == 0)
		{
			return (&commands[i]);
		}
	}
	return ((COMMAND*) NULL);
}

int execute_line(line)
	char* line;
{
	register int i;
	COMMAND* command;
	char* word;
	
	i = 0;
	while(line[i] && whitespace(line[i])) {
		i++;
	}
	word = line + i;
	
	while(line[i] && !whitespace(line[i])) {
		i++;
	}

	if(line[i]) {
		line[i++] = '\0';
	}

	command = find_command(word);
	
	if(!command) {
		printf("Command not found.\n");
		return(-1);
	}

	while(whitespace(line[i])) {
		i++;
	}

	word = line + i;

	return ((*(command->func))(word));
}

void initialize_readline() {
}

char *stripwhite();
/* Strip whitespace from the start and end of STRING.  Return a pointer
   into STRING. */
char* stripwhite(char* string)
{
  register char *s, *t;

  for (s = string; whitespace (*s); s++)
    ;
    
  if (*s == 0)
    return (s);

  t = s + strlen (s) - 1;
  while (t > s && whitespace (*t))
    t--;
  *++t = '\0';

  return s;
}
