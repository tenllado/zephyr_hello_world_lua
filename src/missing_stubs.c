#include <zephyr.h>
#include <stdio.h>

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


int _link(const char *oldpath, const char *newpath)
{
	errno = ENOSYS;
	return -1;
}
