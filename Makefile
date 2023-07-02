CC = gcc

get_thread_info: get_thread_info.o
	$(CC) -pthread get_thread_info.o -o get_thread_info
get_thread_info.o: get_thread_info.c
	$(CC) -c get_thread_info.c
clean:
	rm -f get_thread_info.o