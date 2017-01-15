# folly-mvp0

Like [folly](https://github.com/mes32/folly) ... but less. This is an attempt to make the simplest possible game that somewhat resembles a roguelike.

## Requirements

Most Unix-like systems should have all or nearly all of these already installed, but just in case you need to track some of these down.

- [Make](https://www.gnu.org/software/make/)
- [gcc](https://gcc.gnu.org/) (capable of compiling C99)
- [ncurses](https://github.com/gittup/ncurses)
- [SQLite3](https://sqlite.org/)

## Setup

```
# Clone this repository
git clone https://github.com/mes32/folly-mvp0

# Build main program binary using Makefile
cd folly-mvp0
make

# Run the program
bin/folly-mvp0
```

## Gameplay

```
Controls:

   Arrow Keys - move character
  Number Keys - target a visible enemy with special attack
            i - show inventory screen
            s - save current game
            a - scroll narrative log up
            z - scroll narrative log down
            h - show help screen
            q - quit
```

## License

The code in this repository is licensed under the [MIT License](./LICENSE).