/**
 * @file
 * @brief All logging functions can be efficiently deactivated by defining NLOG
 */
#ifndef C_LOGGER_H
#define C_LOGGER_H
#include <stdio.h>

/** @enum log_level An enum for the log levels
 * @typedef log_level_t
 * @brief Those are the possible log levels
 */
typedef enum log_level
{
    C_LOGGER_DEBUG = 1 /**< The value for the DEBUG levels (0b00001)*/,
    C_LOGGER_VERBOSE = 2 /**< The value for the VERBOSE levels (0b00010)*/,
    C_LOGGER_INFO = 4 /**< The value for the INFO levels (0b00100)*/,
    C_LOGGER_ERROR = 8 /**< The value for the ERROR levels (0b01000)*/,
    C_LOGGER_CONFIRMATION = 16 /**< The value for the CONFIRMATION levels (0b10000)*/
} log_level_t;

#ifdef NLOG
#define c_logger_log(level, str, ...) ;
#define c_logger_set_level(level) ;
#define c_logger_set_output(file) ;
#endif

/** @fn log_level_t c_logger_log(log_level_t level, const char *str, ...)
 * @brief prints the given message if the given logging level is activated
 * @param level The logging level
 * @param str The given message
 * @param ... The arguments for the format string
 * @returns The logging level or 0 if the level was deactivated
 */
log_level_t c_logger_log(log_level_t level, const char *str, ...);

/** @fn void c_logger_set_level(log_level_t level)
 * @brief switches the given logging levels on/off (multiple levels can be combined using the or operator)
 * @param level The level(s) to be turned on/off
 * @returns void
 */
void c_logger_set_level(log_level_t level);

/** @fn void c_logger_set_output(FILE *file)
 * @brief Sets the output for the logging messages
 * @param file The output file (A pointer to a file or stdout/stderr).
 * @returns void
 */
void c_logger_set_output(FILE *file);

#endif // C_LOGGER_H
