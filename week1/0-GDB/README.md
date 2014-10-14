# GDB

make a program - a_program

gdb ./a_program


breakpoints:
```bash
b main
b function_name
b 23 #line number
b filenam.c:45 #line number
```

running:
```bash
r <arguments>
run <arguments>
```

code viewing:
```bash
layout
Ctrl+X A - get out ot layout mode
layout next - have fun with assembler
```

code browsing:
```bash
n - step over
s - step in
f - step out

bt - backtrace
f [number] - move the focus to a place in the stack
```
printing values:
```bash
p variable_name - prints
p *struct_pointer - prints very pretty :)
info locals - prints locals
```

Press F6 F8 to move through command history in layout mode, thank you Momchil :)
