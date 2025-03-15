// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>

int puts(const char *string)
{
    // case for NULL input string
    if (NULL == string)
    {
        errno = EINVAL;
        return -1;
    }

    int length = strlen(string);
    // write the string and check if there is an error
    int res = syscall(1, 1, string, length);
    if (0 > res)
    {
        errno = -res;
        return -1;
    }
    // write the newline and check if there is an error
    res = syscall(1, 1, "\n", 1);
    if (0 > res)
    {
        errno = -res;
        return -1;
    }
    // return how many characters have been written
    return length + 1;
}
