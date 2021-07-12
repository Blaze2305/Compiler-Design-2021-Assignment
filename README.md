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


## Example

With the given test file: validTestInput.txt
``` 
global
	def
		a:int;
		c,b:int;
	end
	a = 1;
	b = 7;
	if a == b :
		print a;
	else
		print b;
	end;
	while a < 5:
		b = b * 2;
		a = a + 10;
	end;
	print b;
end
```
We can run the parser by : 

```bash
$ bin/tutorial.exe validTestInput.txt
```

### Output : 
```
----------------------------------------------------------------------------
validTestInput.txt
----------------------------------------------------------------------------
Accepted token Global in line 1 as global
Accepted token Def in line 2 as def
Accepted token Identifier in line 3 as a
Accepted token Colon in line 3 as :
Accepted token Type in line 3 as int
Accepted token SemiColon in line 3 as ;
Accepted token Identifier in line 4 as c
Accepted token Comma in line 4 as ,
Accepted token Identifier in line 4 as b
Accepted token Colon in line 4 as :
Accepted token Type in line 4 as int
Accepted token SemiColon in line 4 as ;
Accepted token End in line 5 as end
Accepted token Identifier in line 6 as a
Accepted token Assignment in line 6 as =
Accepted token Number in line 6 as 1
Accepted token SemiColon in line 6 as ;
Accepted token Identifier in line 7 as b
Accepted token Assignment in line 7 as =
Accepted token Number in line 7 as 7
Accepted token SemiColon in line 7 as ;
Accepted token If in line 8 as if
Accepted token Identifier in line 8 as a
Accepted token Conditional in line 8 as ==
Accepted token Identifier in line 8 as b
Accepted token Colon in line 8 as :
Accepted token Print in line 9 as print
Accepted token Identifier in line 9 as a
Accepted token SemiColon in line 9 as ;
Accepted token Else in line 10 as else
Accepted token Print in line 11 as print
Accepted token Identifier in line 11 as b
Accepted token SemiColon in line 11 as ;
Accepted token End in line 12 as end
Accepted token SemiColon in line 12 as ;
Accepted token While in line 13 as while
Accepted token Identifier in line 13 as a
Accepted token Conditional in line 13 as <
Accepted token Number in line 13 as 5
Accepted token Colon in line 13 as :
Accepted token Identifier in line 14 as b
Accepted token Assignment in line 14 as =
Accepted token Identifier in line 14 as b
Accepted token Operator in line 14 as *
Accepted token Number in line 14 as 2
Accepted token SemiColon in line 14 as ;
Accepted token Identifier in line 15 as a
Accepted token Assignment in line 15 as =
Accepted token Identifier in line 15 as a
Accepted token Operator in line 15 as +
Accepted token Number in line 15 as 10
Accepted token SemiColon in line 15 as ;
Accepted token End in line 16 as end
Accepted token SemiColon in line 16 as ;
Accepted token Print in line 17 as print
Accepted token Identifier in line 17 as b
Accepted token SemiColon in line 17 as ;
Accepted token End in line 18 as end
VALID CODE
----------------------------------------------------------------------
                          SYMBOL TABLE

    Symbol Name           Type        Line Number
----------------------------------------------------------------------
              a            int                   3
              b            int                   4
              c            int                   4
----------------------------------------------------------------------
```

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