#include <stdlib.h>

#include "city.h"
#include "salloc.h"

City	*new_city (char *name)
{
	City *city		= safe_malloc (sizeof (City));

	city->name		= name;
	city->roads		= NULL;
	city->next		= NULL;

	return city;
}


void delete_city (City *city)
{
	if (city != NULL)
	{
		delete_roads (city->roads);
		free (city->name);
		free (city);
	}
}
