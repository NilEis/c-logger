#include "c_logger.h"
#include <stdarg.h>
#include "terminal.h"
#ifdef __GNUC__
#define branch_prediction(condition, expected) __builtin_expect(condition, expected)
#elif
branch_prediction(condition, expected) condition
#endif

static FILE *output = NULL;
static log_level_t active_levels = 31 /*0b11111*/;

log_level_t c_logger_log(log_level_t level, const char *str, ...)
{
    if (branch_prediction(output == NULL, 0))
    {
        output = stderr;
    }
    if ((level & active_levels) != 0)
    {
        switch (level)
        {
        case C_LOGGER_DEBUG:
#ifdef NDEBUG
            return 0;
#endif
            if (output == stderr || output == stdout)
            {
                terminal_set_color(WHITE, BLACK);
            }
            break;
        case C_LOGGER_VERBOSE:
            if (output == stderr || output == stdout)
            {
                terminal_set_color(GRAY, BLACK);
            }
            break;
        case C_LOGGER_INFO:
            if (output == stderr || output == stdout)
            {
                terminal_set_color(LIGHT_WHITE, BLACK);
            }
            break;
        case C_LOGGER_ERROR:
            if (output == stderr || output == stdout)
            {
                terminal_set_color(RED, BLACK);
            }
            break;
        case C_LOGGER_CONFIRMATION:
            if (output == stderr || output == stdout)
            {
                terminal_set_color(GREEN, BLACK);
            }
            break;
        }
        va_list args;
        va_start(args, str);
        vfprintf(output, str, args);
        if (output == stderr || output == stdout)
        {
            terminal_set_color(LIGHT_WHITE, BLACK);
        }
        return level;
    }
    return 0;
}

void c_logger_set_level(log_level_t level)
{
    active_levels ^= level;
}

void c_logger_set_output(FILE *file)
{
    output = file;
}