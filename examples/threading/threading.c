#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;

    int success;
    thread_func_args->thread_complete_success = true;

    usleep(1000*thread_func_args->wait_to_obtain_ms);

    success = pthread_mutex_lock(thread_func_args->mutex);
    if (success != 0){
        thread_func_args->thread_complete_success = false;
        printf("Failed to lock the mutex, error code: %d", success);
    }

    usleep(1000*thread_func_args->wait_to_release_ms);

    success = pthread_mutex_unlock(thread_func_args->mutex);
    if (success != 0){
        thread_func_args->thread_complete_success = false;
        printf("Failed to unlock the mutex, error code: %d", success);
    }

    return thread_func_args;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex,int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */

    struct thread_data *dat;

    dat = malloc(sizeof(*dat));

    dat->mutex = mutex;
    dat->wait_to_obtain_ms = wait_to_obtain_ms;
    dat->wait_to_release_ms = wait_to_release_ms;

    int success;
    success = pthread_create(thread, NULL, threadfunc, dat);
    if(success != 0){
        printf("Failed to create a new thread, error code: %d", success);
        return false;
    }

    return true;
}

