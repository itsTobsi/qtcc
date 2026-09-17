# GDB Notes

Run `gdb ./{the program}`
Set a breakpoint `break MainWindow::calculate` then `run`

### Commands

run/r
print var
info locals
next
step
finish/f
continue/c
disassemble
disassemble /s
disassemble calc::add  (this will show the assembly of the function)

### TUI

layout asm (Assembly panel, will show current instruction)
layout regs (Adds a live register panel on the top)
layout src (Adds the source code, next will go to the next line)
layout split (src will go fullscreen so it's needed if you want to read the asm)

next or n(next line in the code)
nexti or ni(next asm instruction)
step or s (Step over)
stepi or si (Step over asm instruction)

print nameOfVar (Will print the variable data)
display nameOfVar (Will print the variable data every step)
watch r (Watch for changes)

print also has a few formats.
print/char nameOfVar
So here's the formats:

- print/d var (Decimal)
- print/f var (Float)
- print/x var (Hex)
- print/o var (Octal)
- print/t var (Binary)
- print/s var (String)
- print/c var (Char)
- print/a var (Address)
- print/u var (Unsigned decimal)
- print/? var ()

From [here](https://visualgdb.com/gdbreference/commands/print).
