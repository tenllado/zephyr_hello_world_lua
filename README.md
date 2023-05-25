# Zephyr Hello World example with Lua

## Development setup

You should have west installed. Then go to the directory where you want the 
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

Yo can change the target board, for instance for a st discovery l475 iot1 you
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

## Lua module for zephyr and missing stubs

This example has been adapted to use the still unofficial lua module for zephyr
in [https://github.com/tenllado/](https://github.com/tenllado/). Lua is an ANSI
C library, but the implementation of some of the functions it uses in picolib
and newlib (the C libraries shipped with zephyr) currently depend on some POSIX
symbols not provided by the POSIX_API in zephyr. Until these problems are solved
the library provides weak *not supported* versions of these functions in the
missing_stubs.c file. You can provide a better implementation on your project.

The functions currently required depend on the libc choosed. For NEWLIB_LIBC
three non supported stubs are provided:

- ``_open()``
- ``_times()``
- ``_unlink()``

In case of the PICOLIBC, only one function is missing:

- ``times()`` 

The latter case can be solved if pull request [57832](https://github.com/zephyrproject-rtos/zephyr/pull/57832)
is accepted.

Using PICOLIB requires and additional change in one header file of zephyr, as
reported in pull request
[57800](https://github.com/zephyrproject-rtos/zephyr/pull/57800).
If these pull requests are accepted, using PICOLIBC would be the best option.

