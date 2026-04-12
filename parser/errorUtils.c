#include "errorUtils.h"

void perror_debug(const char * function, const char *msg)
{
    char buffer[256] = {0};
    snprintf(buffer, sizeof(buffer), "[%s] %s", function, msg);

    if (errno == 0) {
        errno = EINVAL; // Set a default error code if errno is not set
    }

    perror(buffer);
}