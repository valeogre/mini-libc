#ifndef TIME_H
#define TIME_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef long time_t;
    typedef long clock_t;

    struct tm
    {
        int tm_sec;   /* seconds after the minute [0, 60] */
        int tm_min;   /* minutes after the hour [0, 59] */
        int tm_hour;  /* hours since midnight [0, 23] */
        int tm_mday;  /* day of the month [1, 31] */
        int tm_mon;   /* months since January [0, 11] */
        int tm_year;  /* years since 1900 */
        int tm_wday;  /* days since Sunday [0, 6] */
        int tm_yday;  /* days since January 1 [0, 365] */
        int tm_isdst; /* daylight saving time flag */
    };

    struct timespec
    {
        long tv_sec; // seconds
        long tv_nsec; // nanoseconds
    };

    // sleep functions
    int nanosleep(const struct timespec *req, struct timespec *rem);
    unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif /* TIME_H */
