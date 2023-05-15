#ifndef PROCESS_LOG_H
#define PROCESS_LOG_H

#define PROC_GET_CALL 435
#define PROC_SET_CALL 436
#define PROC_LOG_CALL 437

// 	Library function declarations

int get_proc_log_level();
/* Invokes the system call which reads the system-wide process log level.
    - If successful, returns the process log level
    - Otherwise, returns -1	*/

int set_proc_log_level(int new_level);
/* Invokes the system call which attempts to change the system-wide process logLevel to new_level
    - If successful, returns new_level
    - Otherwise, returns -1 (logLevel should not be changed)  */

int proc_log_message(int level, char *message);
/* Invokes the system call to log a message for this process
    - If logged, the message should appear in dmesg logs at the corresponding kernel level
    - Returns -1 for invalid log levels or if message is too long
    - Otherwise, returns level   */


//	Harness function declarations

int* retrieve_set_level_params(int new_level);
// Returns an int array of 2 to 4 values that can be used to make the "set_proc_log_level" system call

int* retrieve_get_level_params();
// Returns an int array of 2 to 4 values that can be used to make the "get_proc_log_level" system call

int interpret_set_level_result(int ret_value);
// After making the system call, we pass the syscall's return value to this function call
//   - It should return "set_proc_log_level"s interpretation of the syscall completing with return value "ret_value"

int interpret_get_level_result(int ret_value);
// After making the system call, we pass the syscall's return value to this function call
//   - It should return "get_proc_log_level"s interpretation of the syscall completing with return value "ret_value"

int interpret_log_message_result(int ret_value);
// After making the system call, we pass the syscall's return value to this function call
//   - It should return "proc_log_message"s interpretation of the syscall completing with return value "ret_value"

#endif
