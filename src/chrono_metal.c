#include "chrono.h"

#include <stddef.h>
#include <metal/time.h>

static struct timeval chrono_struct;
static uint64_t* chrono_slots;

void chrono_init(uint64_t* slots)
{
	chrono_slots = slots;
}

void chrono_start(uint32_t id)
{
	gettimeofday(&chrono_struct, NULL);
	chrono_slots[id] = ((uint64_t) chrono_struct.tv_usec)
		+ (((uint64_t) chrono_struct.tv_sec) * 1000000);
}

uint64_t chrono_stop(uint32_t id)
{
	gettimeofday(&chrono_struct, NULL);

	return ((uint64_t) chrono_struct.tv_usec)
		+ (((uint64_t) chrono_struct.tv_sec) * 1000000)
	 	- chrono_slots[id];
}
