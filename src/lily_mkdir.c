/**
library mkdir

A humble wrapper for mkdir (or _mkdir if Windows).

This provides Lily the ability to create a directory, but doesn't include any
error handling.
*/

#ifdef _WIN32
# include <direct.h>
#else
# include <sys/stat.h>
#endif

#include "lily.h"

/** Begin autogen section. **/
const char *lily_mkdir_info_table[] = {
    "\0\0"
    ,"F\0mkdir\0(String,*Integer)"
    ,"Z"
};
void lily_mkdir__mkdir(lily_state *);
lily_call_entry_func lily_mkdir_call_table[] = {
    NULL,
    lily_mkdir__mkdir,
};
/** End autogen section. **/

/**
define mkdir(filename: String, mode: *Integer=511)

Attempt to create the directory `filename`. On *nix systems, 
*/
void lily_mkdir__mkdir(lily_state *s)
{
    char *to_make = lily_arg_string_raw(s, 0);

#ifdef _WIN32
    _mkdir(to_make);
#else
    int mode = 0777;

    if (lily_arg_count(s) == 2)
        mode = lily_arg_integer(s, 1);

    mkdir(to_make, mode); 
#endif
}
