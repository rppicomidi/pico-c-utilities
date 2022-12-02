# pico-c-utilities
A collection of C and C++ functions for console I/O and other useful things for the Raspberry Pi Pico.

Each file in this directory contains a single C function, a single C++ class, or a collection
of related C functions that are useful across many projects. They are collected here to
prevent copying them all over the place.

Include this project in your project as a git submodule.

## Utility Descriptions

### getsn.c/h
- Language: C
- Requires: `pico-sdk` for the Raspberry Pi Pico
- Provides: `int getsn(char* cp, int size)`, a function for getting
a character string from the console.
- Notes: inspired by FreeBSD function of the same format.

