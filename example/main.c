#include "c_logger.h"
#include <stdlib.h>

int main(int argc, char const **argv)
{
    c_logger_set_output(stdout);
    c_logger_log(C_LOGGER_DEBUG, "Debug message\n");
    c_logger_log(C_LOGGER_VERBOSE, "Verbose message\n");
    c_logger_log(C_LOGGER_INFO, "Info message %d\n", 1);
    c_logger_log(C_LOGGER_ERROR, "Error message\n");
    c_logger_log(C_LOGGER_CONFIRMATION, "Confirmation message\n");
    c_logger_set_level(C_LOGGER_ERROR);
    c_logger_log(C_LOGGER_CONFIRMATION, "Deactivated error messages\n");
    c_logger_log(C_LOGGER_ERROR, "Error messages will not work\n");
    c_logger_log(C_LOGGER_INFO, "Info messages will work\n");
    c_logger_set_level(C_LOGGER_ERROR);
    c_logger_log(C_LOGGER_CONFIRMATION, "Reactivated error messages\n");
    FILE *output = fopen("example_log.log", "w");
    c_logger_set_output(output);
    c_logger_log(C_LOGGER_INFO, "Log in File");
    fclose(output);
    return 0;
}
