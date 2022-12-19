# Compiler-Lab
KTU S7 Compiler Laboratory Source Codes CSL 411

```console
# To simulate LEX  programs use 
$ flex lex.l && gcc lex.yy.c -ll && ./a.out

# To simulate YACC programs use 
$ yacc -d yacc.y && flex lex.l && gcc y.tab.c lex.yy.c -ll && ./a.out
```


### Record Index
| No. | Date       | Source | Title                           |  Link                                                                                |
| --- | ---------- | ------ | ------------------------------- | -------------------------------------------------------------------------------------|
| 01  | 28/09/2022 | C      | Lexical analyser for C Language |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e01_lexical/p1_v1.c)    |
| 02  | 06/10/2022 | LEX    | Lexical analyser for C Language |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e02_lex/lexical/lex.l)  |
| 03  | 21/10/2022 | LEX    | Count lines, words & characters |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e02_lex/line_word/lex.l)|
| 04  | 21/10/2022 | LEX    | Replace substring               |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e02_lex/substr/lex.l)   |
| 05  | 21/10/2022 | LEX    | Count vowels and consonants     |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e02_lex/vowcon/lex.l)   |
| 06  | 26/10/2022 | YACC   | Arithmetic expression validator |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/arithmetic)    |
| 07  | 28/10/2022 | YACC   | Basic identifier validator      |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/identifier)    |
| 08  | 28/10/2022 | YACC   | Arithmetic expression evaluator |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/evaluvator)    |
| 09  | 18/11/2022 | C      | ∈ - Closure of all states       |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e04_eps/eps.c)          |
| 10  | 18/11/2022 | C      | ∈ - NFA to NFA                  |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e05_enfa/enfa.c)        |
| 11  |            | C      | NFA to DFA                      |                                                                                    |
| 12  | 25/11/22   | C      | First and Follow of Grammar     |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e07_fifo/fifo.c)        |
| 13  | 09/12/2022 | C      | Recursive Descent Parser        |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e08_rdp/rdp.c)          |
| 14  | 09/12/2022 | C      | Shift Reduce Parser             |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e09_srp/srp.c)          |
| 15  | 17/12/2022 | C      | Intermediate Code Generation    |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e10_icg/icg.c)          |
| 16  | 17/12/2022 | C      | Constant Propagation            |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e11_cp/cp.c)          |
| 16  | 17/12/2022 | C      | Assembly Code Generation        |  [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e12_assembly/assembly.c)          |

### Addon Experiments
| No. | Date       | Source | Title            | Link                                                                              |
| --- | ---------- | ------ | ---------------- | ----------------------------------------------------------------------------------|
| 01  | 06/10/2022 | LEX    | Count Vowels     | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e02_lex/vowcon/lex.l) |
| 02  | 06/10/2022 | LEX    | Real Numbers     | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e02_lex/real/lex.l)   |
| 03  | 28/10/2022 | YACC   | Zero One         | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/addon/01)    |
| 04  | 28/10/2022 | YACC   | AnBn             | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/addon/anbn)  |
| 05  | 28/10/2022 | YACC   | Infix to Postfix | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/addon/inpost)|
| 06  | 28/10/2022 | YACC   | Palindrome       | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e03_yacc/addon/palin) |

### Exam Experiments

| No. | Date       | Source | Title            | Link                                                                                |
| --- | ---------- | ------ | -----------------| ----------------------------------------------------------------------------------- |
| 01  | 19/10/2022 | LEX    | Calculator       | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q01/lex.l) |
| 02  | 19/10/2022 | LEX    | Line Space Tabs  | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q02/lex.l) |
| 03  | 19/10/2022 | LEX    | C Comments       | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q03/lex.l) |
| 04  | 19/10/2022 | LEX    | Multi - Space    | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q04/lex.l) |
| 05  | 19/10/2022 | LEX    | Positive Negative| [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q05/lex.l) |
| 06  | 19/10/2022 | LEX    | Longest Length   | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q06/lex.l) |
| 07  | 19/10/2022 | LEX    | Odd Even         | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q07/lex.l) |
| 08  | 19/10/2022 | LEX    | Prime            | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q08/lex.l) |
| 09  | 19/10/2022 | LEX    | Leap Year        | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q09/lex.l) |
| 10  | 19/10/2022 | LEX    | Armstrong        | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e02_lex/exam/q10/lex.l) |

### References
| No. | Title     | Link                                                                             |
| --- | --------- | -------------------------------------------------------------------------------- |
| 01  | LEX       | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/references/lex.pdf)  |
| 02  | YACC      | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/references/yacc.pdf) |
| 03  | GNU BISON | [🔗](https://www.gnu.org/software/bison/manual/bison.html)                       |
