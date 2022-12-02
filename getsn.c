/**
 * MIT License
 *
 * Copyright (c) 2022 rppicomidi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */
#include <ctype.h>
#include <stdio.h>
#include "pico/stdio.h"
#include "getsn.h"
 
int getsn(char *cp, int size)
{
    int c = getchar_timeout_us(0);
    int idx = 0;
    while (idx < size-1 && c != '\n' && c != '\r') {
        if (c != PICO_ERROR_TIMEOUT) {
            if (c == '\b' && idx > 0) {
                printf("\b \b");
                --idx;
            }
            else if (isprint(c)) {
                printf("%c", c);
                cp[idx++] = c;
            }
        }
        c = getchar_timeout_us(0);
    }
    printf("\r\n");
    cp[idx] = '\0';
    return idx;
}

