# Zephyr Hello World example with Lua


## Development setup

You should have west installed. Then go to the directory where you want the sol
workspace to be created and then run de following commands:

```bash
$ west init -m git@github.com:tenllado/zephyr_hello_world_lua.git --mr master workspace
$ cd workspace
$ west update
```

The last command will download the zephyr project selected in the manifest file
(west.yml) and the lua code at the version selected in the manifest file.

Once that is completed you can compile it as:

```bash
$ cd app
$ west build -b qemu_x86 -d build
```

Then you can run it like:

```bash
$ cd build
$ west build -t run
```
or change the last command by:

```bash
$ ninja run
```

Yo can change the target board, for instance for a nxp discovery l475 iot1 you
can use:

```bash
$ west build -b disco_l475_iot1
$ cd build
$ west flash
```

you will get a message in the standard output (monitor it with minicomo or
similar program in the case you are using an external board) similar to this:

```
*** Booting Zephyr OS build 3f8d5c49b3fb  ***
Starting lua code
Hello from Lua
Test Done!
```

## Missing newlib stubs

We had to add a "operation not supported" implementation for three newlib stubs
that seems no to be implemented by the newlib libc that ships with zephyr. These
three stubs, implemented in the src/missing_stubs.c file, are:

```c
clock_t _times(struct tms* tms);
int _unlink(const char *pathname);
int _link(const char *oldpath, const char *newpath);
```

Any help to solve this issue will be appreciated.

