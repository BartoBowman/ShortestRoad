#include <stdlib.h>

#include "road.h"
#include "salloc.h"

Road *new_road (City *origin, City *destination, unsigned int length)
{
	 Road *road		= safe_malloc (sizeof (Road));

	 road->origin		= origin;
	 road->destination	= destination;
	 road->length		= length;
	 road->next		= NULL;

	 return road;
}


void delete_road (Road *road)
{
	if (road != NULL)
		free (road);
}


void delete_roads (Road *roads)
{
	Road *roads_copy;

	while (roads)
	{
		roads_copy = roads;
		roads = roads->next;
		delete_road (roads_copy);
	}
}
