#define _XOPEN_SOURCE 700

#include "chrono.h"

#include <stddef.h>
#include <time.h>

static struct timespec chrono_struct;
static uint64_t* chrono_slots;

void chrono_init(uint64_t* slots)
{
	chrono_slots = slots;
}

void chrono_start(uint32_t id)
{
	clock_gettime(CLOCK_MONOTONIC, &chrono_struct);

	chrono_slots[id] =
		(((uint64_t) chrono_struct.tv_nsec) / 1000)
		+ (((uint64_t) chrono_struct.tv_sec) * 1000000);
}

uint64_t chrono_stop(uint32_t id)
{
	clock_gettime(CLOCK_MONOTONIC, &chrono_struct);

	return (((uint64_t) chrono_struct.tv_nsec) / 1000)
		+ (((uint64_t) chrono_struct.tv_sec) * 1000000)
	 	- chrono_slots[id];
}
