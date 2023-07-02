#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <linux/sched.h>
#include <pthread.h>

#define TUN_DEV "/dev/net/tun"
#define TUN_NAME "mytun"

int tun_alloc(char *dev)
{
    struct ifreq ifr;
    int fd, err;

    if ((fd = open(TUN_DEV, O_RDWR)) < 0)
    {
        return fd;
    }

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
    if (*dev)
    {
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    }

    if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0)
    {
        close(fd);
        return err;
    }

    strcpy(dev, ifr.ifr_name);
    return fd;
}

int main()
{
    char tun_name[IFNAMSIZ];
    int tun_fd = -1;

    if ((tun_fd = tun_alloc(tun_name)) < 0)
    {
        perror("Failed to create TUN interface");
        exit(1);
    }

    printf("TUN interface %s created.\n", tun_name);

    printf("%lu", pthread_self());

    return 0;
}