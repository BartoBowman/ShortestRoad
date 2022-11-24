#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *check_pointer (void *p)
{
	if (p == NULL)
	{
		printf ("Error: out of memory!\n");
		exit (1);
	}
	return p;
}

void *safe_malloc (size_t size)
{
	return check_pointer (malloc (size));
}


char *safe_strdup (const char *string)
{
	return strcpy (safe_malloc (strlen (string) + 1), string);
}
