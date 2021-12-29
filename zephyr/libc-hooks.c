/*
 * Copyright © 2021, Keith Packard <keithp@keithp.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <toolchain.h>
#include <sys/printk.h>
#include <sys/libc-hooks.h>

#include "stdio.h"

static FILE __stdio = FDEV_SETUP_STREAM(NULL, NULL, NULL, 0);

#ifdef __strong_reference
#define STDIO_ALIAS(x) __strong_reference(stdin, x);
#else
#define STDIO_ALIAS(x) FILE *const x = &__stdio;
#endif

FILE *const stdin = &__stdio;
STDIO_ALIAS(stdout);
STDIO_ALIAS(stderr);

void __stdout_hook_install(int (*hook)(int))
{
    (void)hook;
}

void __stdin_hook_install(unsigned char (*hook)(void))
{
    (void)hook;
}

__weak void _exit(int status)
{
    (void)status;

    printk("exit\n");
    while (1) {}
}

__weak void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
    (void)file;
    (void)line;
    (void)func;
    (void)failedexpr;
    k_panic();
    /* NOTREACHED */
}

__weak FUNC_NORETURN void __chk_fail(void)
{
    //static const char chk_fail_msg[] = "* buffer overflow detected *\n";
    //_write(2, chk_fail_msg, sizeof(chk_fail_msg) - 1);
    printk("* buffer overflow detected *\n");
    k_oops();
    CODE_UNREACHABLE;
}
