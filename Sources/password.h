/* password.h - ECE594 Group 1 */

#ifndef PASSWORD_H
#define PASSWORD_H

#include "PE_Types.h"

// Uncomment if testing on a platform without appropriate types.
/* #ifdef __linux__
#include <stdbool.h>
#define byte unsigned char
#define bool _Bool
#define FALSE false
#define TRUE true
#endif */

void init_password(void);

void set_password(char*, byte);

bool validate_password(char*, byte);

bool authenticate_password(char*, byte);

bool is_password_set(void);

#endif // PASSWORD_H
