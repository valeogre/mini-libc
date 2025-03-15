#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;

    req.tv_sec = seconds;
    req.tv_nsec = 0;

    // checking if nanosleep fails and returns the remaining time
    if (-1 == nanosleep(&req, &rem))
    {
        if (rem.tv_sec < 0)
        {
            return 0;
        }
        return (unsigned int)rem.tv_sec;
    }

    return 0;
}
