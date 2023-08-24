# monty

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

### Monty Byte Code Files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

For example(`file.m`):
`push 1
pint
push 2
pint
push 3
pint`

## Compilation & Output
`gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty && ./monty`

|OPCODE|DESCRIPTION|
--------------------
|`push`| pushes an element to the stack|
|`pall`| prints all the values on the stack, starting form the top|
|`pint`| prints the value at the top of the stack|
|`pop`| removes the top element|
|`swap`| swaps the top 2 elements of the stack|
|`add`| adds the top 2 elements of the staack|
|`nop`| doesn't anything|

