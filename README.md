Mini-libc: Minimalistic Standard C Library for Linux
This project implements a minimalistic standard C library (mini-libc) for Linux, designed to replace the system libc (glibc) with a freestanding version. The library is implemented on top of the Linux syscall interface for the x86_64 architecture and focuses on providing core functionalities such as string management, memory support, and POSIX file I/O without relying on external libraries.

Features:
- String Functions: Includes essential functions like strcpy(), strlen(), strcmp(), memcpy(), etc.
- Memory Management: Implements malloc(), free(), calloc(), realloc(), etc., using system calls.
- I/O Operations: Implements basic I/O functions like open(), close(), puts(), and lseek().
- System Calls: Directly interfaces with Linux system calls using syscall().

The project aims to provide a minimal functional alternative to the system C library, enhancing understanding of low-level system operations.

