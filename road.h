#ifndef _ROAD_H_
#define _ROAD_H_

typedef struct road Road;

#include "city.h"

struct road
{
	City		*origin;
	City		*destination;
	unsigned int	length;
	Road		*next;
};

Road *new_road (City *origin, City *destination, unsigned int length);
void delete_road (Road *road);
void delete_roads (Road *roads);

#endif /* _ROAD_H_ */
