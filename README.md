# Compiler-Lab
KTU S7 Compiler Laboratory Source Codes CSL 411

```console
# To simulate LEX  programs use 
$ flex lex.l && gcc -g -o lex lex.yy.c -ll && ./lex

# To simulate YACC programs use 
$ yacc -d yacc.y && flex lex.l && gcc -g -o parse y.tab.c lex.yy.c -ll && ./parse
```


### Record Index
| No. | Date       | Source | Title                           | Link                                                                               |
| --- | ---------- | ------ | ------------------------------- | ---------------------------------------------------------------------------------- |
| 01  | 28/09/2022 | C      | Lexical analyser for C Language | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e1_lexical/p1_v1.c)    |
| 02  | 06/10/2022 | LEX    | Lexical analyser for C Language | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e2_lex/lex.l)          |
| 03  | 21/10/2022 | LEX    | Count lines, words & characters | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e2_lex/addon/a1/lex.l) |
| 04  | 21/10/2022 | LEX    | Replace substring               |                                                                                    |
| 05  | 21/10/2022 | LEX    | Count vowels and consonants     | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e2_lex/addon/a2/lex.l) |
| 06  | 26/10/2022 | YACC   | Arithmetic expression validator | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e3_yacc/evaluvator)    |
| 07  | 28/10/2022 | YACC   | Basic identifier validator      | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e3_yacc/identifier)    |
| 08  | 28/10/2022 | YACC   | Arithmetic expression evaluator | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e3_yacc/arithmetic)    |

### Addon Experiments
| No. | Date       | Source | Title            | Link                                                                               |
| --- | ---------- | ------ | ---------------- | ---------------------------------------------------------------------------------- |
| 01  | 06/10/2022 | LEX    | Count Vowels     | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e2_lex/addon/a2/lex.l) |
| 02  | 06/10/2022 | LEX    | Real Numbers     | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/blob/main/e2_lex/addon/a3/lex.l) |
| 03  | 28/10/2022 | YACC   | Zero One         | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e3_yacc/addon/01)      |
| 04  | 28/10/2022 | YACC   | AnBn             | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e3_yacc/addon/anbn)    |
| 05  | 28/10/2022 | YACC   | Infix to Postfix | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e3_yacc/addon/inpost)  |
| 06  | 28/10/2022 | YACC   | Palindrome       |                                                                                    |

### Exam Experiments

| No. | Date       | Source | Title            | Link                                                                               |
| --- | ---------- | ------ | -----------------| ---------------------------------------------------------------------------------- |
| 01  | 19/10/2022 | LEX    | Calculator       | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q01/lex.l) |
| 02  | 19/10/2022 | LEX    | Line Space Tabs  | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q02/lex.l) |
| 03  | 19/10/2022 | LEX    | C Comments       | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q03/lex.l) |
| 04  | 19/10/2022 | LEX    | Multi - Space    | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q04/lex.l) |
| 05  | 19/10/2022 | LEX    | Positive Negative| [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q05/lex.l) |
| 06  | 19/10/2022 | LEX    | Longest Length   | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q06/lex.l) |
| 07  | 19/10/2022 | LEX    | Odd Even         | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q07/lex.l) |
| 08  | 19/10/2022 | LEX    | Prime            | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q08/lex.l) |
| 09  | 19/10/2022 | LEX    | Leap Year        | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q09/lex.l) |
| 10  | 19/10/2022 | LEX    | Armstrong        | [🔗](https://github.com/EmmanuelJojy/Compiler-Lab/tree/main/e2_lex/exam/q10/lex.l) |


