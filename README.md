# Corewar (42 School Project)
A team project to build your own virtual machine (feat. @mshkliai and @AndreVero)

![Corewar](/images/1.png)

This project can be broken down into three distinctive parts:
* **The assembler**: this is the program that will compile champions and translate them from the language written them in (assembly language) into “Bytecode”. Bytecode is a machine code, which will be directly interpreted by the virtual
machine.
* **The virtual machine**: It’s the “arena” in which champions will be executed. It offers various functions, all of which will be useful for the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes.
* **The champion**: It's necessary to create a simple champion just to prove the program functionality.

### How to run:
* git clonehttps://github.com/itiievskyi/42-corewar.git ~/corewar/
* cd ~/corewar/
* make
* ./asm [file.s] (use *Leha.s*)
* ./corewar [-v | -dump N] [-a] [-n N] <champion1.cor> <...>
  * -v	       : Enables visualization
  * -dump N	: Dumps memory after N cycles
  * -a	       : Prints output from 'aff' (Default is to hide it)
  * -n N	: Assigns id N to the player specified right after N

*Pay attention! [-v] has higher priority when is used with [-dump]*

### Visualization
Visualization is enabled using <ncurses> library. The native shell (for example, Terminal.app for macos) could show higher permormance than the third-party applications like iTerm. Colors may vary depend on your shell application settings.

### Champions
You could get more champions by searching GitHub. For example, take a look [here](https://github.com/lodow/corewar/tree/master/champ).

### Enjoy!
