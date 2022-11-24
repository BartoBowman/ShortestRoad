/* 
 * Student: R. H. J. Claasen
 * Number: 3074994
 * Assignment: 5.2
 */

/*
 * Student: B. T. Visser
 * Number: 3084566
 * Assignment: 5.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> /* e.g. include UINT_MAX (the maximum unsigned integer value */

#include "salloc.h"
#include "city.h"
#include "road.h"

#define MAX_STRING_LENGTH 100


/*
 * Locate city with name city_name on the map
 */
static City *find_city (City *list_of_cities, char *city_name)
{
	City *c = list_of_cities;
	while (c != NULL)
	{
		if (strcmp (c->name, city_name) == 0)
			return c;

		c = c->next;
	}
	return NULL;
}


/*
 * Delete a map
 */
static void delete_map (City *map)
{
	City *map_copy;

	while (map != NULL)
	{
		map_copy = map;
		map = map->next;
		delete_city (map_copy);
	}
}


/*
 * Build the map datastructure
 */
static City *create_map (FILE *data_file)
{
	int num_of_cities, i;

	City *map = NULL;

	/* Read in city-names	*/
	fscanf (data_file, "%d", &num_of_cities);

	for (i = 0; i < num_of_cities; i++)
	{
		char city_name[MAX_STRING_LENGTH + 1];
		City *city;
		City *c;

		fscanf (data_file, "%s", city_name);

		if (find_city (map, city_name) != NULL)
		{
			fprintf (stdout, "City %s already on the map\n", city_name);
			delete_map (map);
			exit (EXIT_FAILURE);
		}

		city = new_city (safe_strdup (city_name));

		if (map == NULL)
			/* This is the first city of the map */
			map = city;
		else {
			/* Find last of city list */
			c = map;
			while (c->next) c = c->next;
			/* And append new city there */
			c -> next = city;
		}
	}

	/* FIXME (Assignment 5.1)
	 * Read number of roads
	 * For each road:
	 *    Read origin city name, destination city name and length
	 *    Find pointers to orgin city structure and destination city structure
	 *    using the function find_city()
	 *    Create new road structure using new_road() function
	 *    Add it to the list of roads of the origin city.
	 */

	return map;
}


static void print_city_roads (City *map)
{
	City *city;
	Road *road;

	for (city = map; city != NULL; city = city->next)
	{
		printf ("Roads from city %s:\n", city->name);

		for (road = city->roads; road != NULL; road=road->next) {
			printf ("   to city %s", road->destination->name);
			printf (" (length %d)\n", road->length);
		}
	}
}


static void find_shortest_roads (City *map)
{
	/* FIXME  (Assignment 5.2)
	 * While input and input != "0"
	 *    Find pointer to specified city using find_city()
	 *    Visit the roads originating from this city,
	 *    and find the road that has the shortest length
	 *    Print the destination city and the road length.
	 */

}




int main (int argc, char *argv[])
{
	FILE *data_file = NULL;
	City *map = NULL;

	/* Check arguments		*/
	if (argc != 2)
	{
		fprintf (stdout, "Usage: %s <datafile>\n", argv[0]);
		exit (EXIT_FAILURE);
	}

	/* Open data-file		*/
	if ((data_file = fopen (argv[1], "r")) == NULL)
	{
		fprintf (stdout, "Error opening file <%s>\n", argv[1]);
		exit (EXIT_FAILURE);
	}

	/* Create map-data-structure	*/
	if ((map = create_map (data_file)) == NULL)
	{
		fprintf (stdout, "No map data found\n");
		exit (EXIT_FAILURE);
	}

	print_city_roads (map);

	find_shortest_roads (map);

	/* Cleanup			*/
	if (data_file != NULL)
		fclose (data_file);
	if (map != NULL)
		delete_map (map);

	return EXIT_SUCCESS;
}
