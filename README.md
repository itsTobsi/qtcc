# Trying to learn NVIM and qt-6

## And maybe a bit of GDB

run

1. `cmake -B -build -G Ninja -DCMAKE_BUILD_TYPE=Debug`
2. `$ cp ./build/compile_commands.json`
3. `cmake --build build`
4. `./build/HelloQt.exe`

Resources:

- <https://doc.qt.io/qt-6/classes.html>
- <https://doc.qt.io/qt-6/reference-overview.html>
- <https://doc.qt.io/qt-6/layout.html>
- <https://doc.qt.io/qt-6/signalsandslots.html>

- [ASM x64_cheatsheet from Brown University](https://cs.brown.edu/courses/cs033/docs/guides/x64_cheatsheet.pdf)

Sometimes have to run:

```
cmake --build build
cp build/compile_commands.json .
:LspRestart
```
