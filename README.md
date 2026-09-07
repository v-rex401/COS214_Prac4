# COS214_Prac4

- Njabulo
- Rayhaan
- Vashti Pillay - u25041887

## 1. Docker Instructions

1. Run `docker build -t taskforge . ` in the terminal

2. Run `docker run -rm -it taskforge bash`

- -rm - deletes container when it exits
- -i - interactive, keeps stdin open to write commands in container
- -t - Get a command prompt
- bash - tell docker to launch Bash shell

3. When your done to exit container run `exit`

## 2. Makefile Instructions & Running Program

After setting up docker

1. Type `make`
2. After is compiles type `make run` to run it
3. Run `make valgrind` to check for memory leaks
4. Run `gdb ./taskforge` after compiling with `make` to use debugger
