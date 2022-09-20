#ifndef C_LOGGER_H
#define C_LOGGER_H
#include <stdio.h>

typedef enum log_level
{
    C_LOGGER_DEBUG = 1 /*0b00001*/,
    C_LOGGER_VERBOSE = 2 /*0b00010*/,
    C_LOGGER_INFO = 4 /*0b00100*/,
    C_LOGGER_ERROR = 8 /*0b01000*/,
    C_LOGGER_CONFIRMATION = 16 /*0b10000*/
} log_level_t;

#ifdef NLOG
#define c_logger_log(level, str, ...) ;
#define c_logger_set_level(level) ;
#define c_logger_set_output(file) ;
#endif

log_level_t c_logger_log(log_level_t level, const char *str, ...);

void c_logger_set_level(log_level_t level);

void c_logger_set_output(FILE *file);

#endif // C_LOGGER_H
