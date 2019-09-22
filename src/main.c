#include "chrono.h"
#include <stdio.h>
#include <stdint.h>

int main()
{
	uint64_t slots[10];
	int tmp;

	chrono_init(slots);

	tmp = 0;
	chrono_start(0);

	for (int i = 0; i < 10000; ++i)
	{
		tmp += i;
	}

	printf("%lu\n", chrono_stop(0));

	tmp = 0;
	chrono_start(1);

	for (int i = 0; i < 10000; ++i)
	{
		tmp += i;

		if (tmp < 6000)
		{
			chrono_start(2);
		}
	}

	printf("%lu %lu\n", chrono_stop(1), chrono_stop(2));

	return 0;
}
