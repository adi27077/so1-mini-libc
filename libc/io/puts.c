#include <stdio.h>
#include <internal/syscall.h>
#include <internal/io.h>
#include <string.h>

int puts(const char *str)
{
    int len = strlen(str);

    ssize_t ret = write(1, str, len);

    if (ret < 0)
        return -1;

    ret = write(1, "\n", 1);
    if (ret < 0)
        return -1;

    return ret + 1;
}
