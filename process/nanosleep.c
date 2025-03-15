#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int res = syscall(35, req, rem);
    // after nanosleep syscall checking if it failed
    if (-1 == res)
    {
        // setting the remaining time and the errno to a negative value
        if (rem)
        {
            rem->tv_sec = req->tv_sec;
            rem->tv_nsec = req->tv_nsec;
        }
        errno = -res;
        return -1;
    }
    // return 0 for succes
    return 0;
}
