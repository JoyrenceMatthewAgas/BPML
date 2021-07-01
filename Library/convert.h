#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char get_char(char *str, int pv) {
    return str[pv];
}

char make_char(int val) {
    return (char)val;
}

double make_double(int num) {
    return (double)num;
}

float make_float(int num) {
    return (float)num;
}

int make_int(void *var) {
    return atoi(var);
}

const char *make_str_base(char *buf, size_t len, int var) {
    static char loc_buf[sizeof(int) * CHAR_BIT];
    if (!buf) {
        buf = loc_buf;
        len = sizeof(loc_buf);
    }
    if (snprintf(buf, len, "%d", var) == -1) {
        return "";
    }
    return buf;
}

const char *make_str(int var) {
    return make_str_base(NULL, 0, var);
}
