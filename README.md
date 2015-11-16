# projectroot
A simple command-line utility for finding the current project's root.

Borrows lightly from emacs' projectile plugin.

## Usage
The executable will simply print the current project's root directory:
```
$ projectroot
/Users/yamadapc/program/github.com/yamadapc/projectroot
```

### From a child directory
It has a list of project _artifacts_ which it looks for, traversing the FS up.
So it'll print the correct directory if you're on a child:
```
$ mkdir -p $HOME/testing/stuff/here
$ touch $HOME/testing/stuff/package.json
$ cd $HOME/testing/stuff/here
$ projectroot
/Users/yamadapc/testing/stuff
```
We have `package.json` on `$HOME/testing/stuff` and are in
`$HOME/testing/stuff/here`. It goes up and finds the "artifact".

### Prefer the topmost highest priority match
There's a basic concept of *priority* built into `projectroot`. Version Control
System's artifacts, for example, have higher priority than language specific
package manifests. To enable preferring the topmost highest priority match use
the `-t` or `--top` flag:
```
$ mkdir -p $HOME/testing/stuff/here
$ touch $HOME/testing/stuff/package.json
$ cd $HOME/testing
$ git init
$ cd $HOME/testing/stuff/here
$ projectroot -t
/Users/yamadapc/testing
```

This is useful if you have *subprojects* inside a *git* repository, for example,
and want to find the root project directory.

## Help Message
```

  Usage: projectroot [options]

  Options:

    -V, --version                 output program version
    -h, --help                    output help information
    -t, --top                     always prefer the topmost artifact

```

## Installation
Make sure you have `make` and a C compiler. Then run:
```bash
git clone https://github.com/yamadapc/projectroot
cd projectroot
make
```

You can either put the `projectroot` binary in your `PATH` or run:
```bash
make install
```
- - -
### For copy-pasters
```bash
curl -s -L http://git.io/v486r | bash
```

## License
This code is licensed under the GPLv2 license for Pedro Tacla Yamada. Please
refer to the [LICENSE](/LICENSE) file for more information.
