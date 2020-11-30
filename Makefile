CFLAGS = -O3 -fPIC -g -Wall -Werror
CC = gcc
all : myBank myBankh main clean Execute 
.PHONY : clean
clean :
	rm "functions" "header"
myBank : myBank.c
	$(CC) $(CFLAGS) -c myBank.c -o functions
myBankh : myBank.h
	$(CC) $(CFLAGS) -c myBank.h -o header
main : main.c header functions
	$(CC) $(CFLAGS) main.c -o main
Execute : main
	./main