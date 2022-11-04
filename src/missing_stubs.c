#include <zephyr/fs/fs.h>
#include <stdio.h>
#include <errno.h>
#include <sys/times.h>

/* FIXME: this stubs should be properly implemented, in zephyr itself or here.
 * This is just a temporal non-working implementation to start testing lua with
 * zephyr.
 */

clock_t _times(struct tms* tms)
{
	errno = ENOSYS;
	return (clock_t) -1;
}

int _unlink(const char *pathname)
{
	return fs_unlink(pathname);
}

