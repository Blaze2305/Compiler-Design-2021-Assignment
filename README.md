# Compiler Design Tutorials 2021

By : Pranav B , Dharithri M, Venu D

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