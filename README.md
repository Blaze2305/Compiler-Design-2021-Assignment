# Compiler Design Tutorials 2021

By : Pranav B , Dharithri M, Venu D

## How to run

This requires a c++ toolchain capable of compiling c++17 and above . It probably works with c++14 as well, but kept c++17 just to be sure.

Recommended MSVC in windows and g++ in linux/Mac.

This project includes a makefile so to build you will require make to be installed.
For native msvc windows users : 
```cmd
   $ choco install make
```
## Builing and running

```bash
   $ make  
```
This builds a binary in the bin/ folder. This requires a command line arg while running , which is the name of the text file containing the code to be parsed.

## Production Rules :

    Assume # = epsilon
    
- program --> global declList stmtList end
- declList --> decl declList | #
- decl --> def typeList end
- typeList -->  varList : type ; typeListA
- typeListA --> varList : type ; typeListA |  #  
- varList --> var , varList | var 
- var --> identifier
- type --> int |  char
- stmtList --> stmt ; stmtListA
- stmtListA --> stmt ; stmtListA | # 
- stmt --> assignmentStmt | readStmt | printStmt | ifStmt | whileStmt 
- assignmentStmt --> identifier = exp
- readStmt --> read identifier
- printStmt --> print exp
- ifStmt --> if bexp : stmtList elsePart end
- elsePart --> else stmtList | #
- whileStmt --> while bexp : stmtList end
- bexp --> (bexp) | exp < exp bexpA | exp == exp bexpA | not bexp bexpA
- bexpA --> or bexp bexpA | and bexp bexpA | #
- exp --> identifier expA | number expA | (exp)
- expA --> - exp expA | + exp expA | * exp expA | / exp expA | #
- number --> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9