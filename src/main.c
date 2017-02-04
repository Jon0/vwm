#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <xf86drm.h>
#include <xf86drmMode.h>


int drm_open(const char *path) {
	int fd, flags;
	uint64_t has_dumb;

	fd = open(path, O_RDWR);

	/* set FD_CLOEXEC flag */
	if ((flags = fcntl(fd, F_GETFD)) < 0 || fcntl(fd, F_SETFD, flags | FD_CLOEXEC) < 0) {
        	printf("fcntl FD_CLOEXEC failed");
	}


	/* check capability */
	if (drmGetCap(fd, DRM_CAP_DUMB_BUFFER, &has_dumb) < 0 || has_dumb == 0) {
        	printf("drmGetCap DRM_CAP_DUMB_BUFFER failed or doesn't have dumb buffer");
    	}


	return fd;
}


int main(int argc, const char *argv[]) {
    int ret, fd;
    const char *card;
    struct modeset_dev *iter;

    /* check which DRM device to open */
    if (argc > 1)
        card = argv[1];
    else
        card = "/dev/dri/card0";

    fprintf(stderr, "using card '%s'\n", card);
    drm_open(card);

    return EXIT_SUCCESS;
}
