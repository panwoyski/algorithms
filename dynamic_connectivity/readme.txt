Challenge did not stated compilation environment
created and sort of tested under ubuntu 16.04 with g++ 5.4.0

compilation flags in Makefile, -std=c++11 used

problem assumes stdin as data source, stdin buffer gets parsed on startup so
valid program execution is
$ ./solver.out < <input file>
or some pipe usage

Recursive solution left for reference, compiles with
$ make recursive

Could be enhanced with some concurrency, interfaces, boost.graph etc
but lets stay with algorithmic part

