# operating_systems

A repository containing all the solutions of the Operating Systems ECE NTUA Course.


## Useful System Calls

#### open

Opens a specified file.

> `int open(const char *pathname, int flags, mode_t mode)`

> - *pathname*: the filepath specified.
> - *flags*: a bitwise-or of some flags to specify create/open/operation effects.
> - *mode*: optional, specifies the user permissions on the file if created by open. 
> - **returns**: int file descriptor, reference to the file.

#### close 

Closes a specified file.

> `int close(int fd)`

> - *fd*: the file descriptor, reference to the file.
> - **returns**: int, 0 on success, -1 on failure.

#### read 

Read from a file.

> `ssize_t read(int fd, void *buf, size_t count)`

> - *fd*: the file descriptor, reference to the file.
> - *buf*: the buffer to write data to.
> - *count*: the maximum amount of bytes to write to buf.
> - **returns**: ssize_t, on success the amount of bytes read as well as the file position is advanced by this amount, on failure -1.

#### write 

Writes to a file.

> `ssize_t write(int fd, void *buf, size_t count)`

> - *fd*: the file descriptor, reference to the file.
> - *buf*: the buffer to read data from.
> - *count*: the maximum amount of bytes to write into fd.
> - **returns**: ssize_t, on success the amount of bytes written, on failure -1.

## Common File Descriptors

- stdin :   0
- stdout :  1
- stderr :  2
