CC = gcc

network_device: network_device.o
	$(CC) network_device.o -o network_device
network_device.o: network_device.c
	$(CC) -c network_device.c
clean:
	rm -f hello.o