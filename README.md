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

This example has been adapted to use the still unofficial lua module for
zephyr in [https://github.com/tenllado/](https://github.com/tenllado/).

The module right now requires you to provide the missing_stubs.c file found in
this example, because of two problems in zephyr:

- a missing implementation of the ``_times()`` stub for the newlibc or a
  modification of the clock() implementation that does not rely on ``_times()``.
  This has already been reported to zephyr in [bug report 51978](https://github.com/zephyrproject-rtos/zephyr/issues/51978)

- a missing implementation of the ``_unlink()`` stub in the newlibc. This has
  been reported to zephyr in [bug report 51977](https://github.com/zephyrproject-rtos/zephyr/issues/51977)

I plan to request the integration of the lua module in the zephyr project once
these bug reports have been resolved, so that the missing_stubs.c file in this
example is not needed anymore. In the mean time you can use the module like in
this example.


