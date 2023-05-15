#include <unistd.h>
#include <stdlib.h>
#include "process_log.h"

// 	Library function definitions

int get_proc_log_level()
{
    int getResult = syscall(PROC_GET_CALL);
    return getResult;
}

int set_proc_log_level(int new_level)
{
    int setResult = syscall(PROC_SET_CALL, new_level);
    return setResult;
}

int proc_log_message(int level, char *message)
{
    int msgResult = syscall(PROC_LOG_CALL, message, level);
    return msgResult;
}


// 	Harness functions definitions

int* retrieve_set_level_params(int new_level)
{
    int *params = malloc(sizeof(int) * 3);
    params[0] = PROC_SET_CALL;
    params[1] = 1;
    params[2] = new_level;
    return params;
}

int* retrieve_get_level_params() {
    int *params = malloc(sizeof(int) * 2);
    params[0] = PROC_GET_CALL;
    params[1] = 0;
    return params;
}

int interpret_set_level_result(int ret_value) {
    return ret_value;
}

int interpret_get_level_result(int ret_value) {
    return ret_value;
}

int interpret_log_message_result(int ret_value) {
    return ret_value;
}
