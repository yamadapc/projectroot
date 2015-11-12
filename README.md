# projectroot
A simple command-line utility for finding the current project's root.

Borrows lightly from emacs' projectile plugin.

## Installation
Make sure you have `make`, [`clib`](https://github.com/clibs/clib#installation)
and a C compiler. Then run:
```bash
git clone https://github.com/yamadapc/projectroot
clib install
cd projectroot
make
```

You can either put the `projectroot` binary in your `PATH` or run:
```bash
make install
```

## License
This code is licensed under the GPLv2 license for Pedro Tacla Yamada. Please
refer to the [LICENSE](/LICENSE) file for more information.
