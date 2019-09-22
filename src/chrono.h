#ifndef H_CHRONO
#define H_CHRONO

#include <stdint.h>

// no context to speed things up
void chrono_init(uint64_t* slots);
// returns false if all chrono slots are taken
void chrono_start(uint32_t id);
// returns the number of microseconds since start
uint64_t chrono_stop(uint32_t id);

#endif
