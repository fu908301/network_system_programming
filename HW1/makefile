all:shell
cc=gcc 
CFLAGS=-g -Wall -ansi
my_shell=shell.o builtin.o run_command.o is_background.o parse.o
shell:$(my_shell)
	$(cc)-o$@ $(my_shell)
dep: $(my_shell:.o=.c)
	$(cc) -MM $^ > depend
%.c:%.o
	$(cc)$(CFLAGS)-c-o$@ $<
clean:
	rm *.o
