#ifndef _LOG_H_
#define _LOG_H_
#include <stdio.h>
#include <stdlib.h>

#define Log(content, ...) printf(content, __VA_ARGS__)

#endif // !_LOG_H_

