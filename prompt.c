#include "main.h"

/**
 * prompt - calls prompt from another function
 *
 **/
void prompt(void)
{
	for (;;)
	{
		char *text = NULL, **env;
		pid_t cpid;
		int status, lenbuf;
		size_t bufsize = 0;

		place("$ ");
		lenbuf = getline(&text, &bufsize, stdin);
		if (lenbuf == -1)
			exit(98);
		if (compareExit(text, "exit") == 0)
			exit(0);
		if (compareEnv(text, "env") == 0)
		{
			while (*env != NULL)
			{
				if (!(_strcmpdir(*environ, "USER")) ||
						!(_strcmpdir(*env, "LANGUAGE")) ||
						!(_strcmpdir(*env, "SESSION")) ||
						!(_strcmpdir(*env, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmpdir(*env, "SHLV")) ||
						!(_strcmpdir(*env, "HOME")) ||
						!(_strcmpdir(*env, "C_IS")) ||
						!(_strcmpdir(*env, "DESKTOP_SESSION")) ||
						!(_strcmpdir(*env, "LOGNAME")) ||
						!(_strcmpdir(*env, "TERM")) ||
						!(_strcmpdir(*env, "PATH")))
				{
					place(*env), place("\n"); }
				env++; }}
		cpid = fork();
		if (cpid < 0)
			perror("Error");
		if (cpid == 0)
			identify_string(text);
		else
			wait(&status);
	}}
