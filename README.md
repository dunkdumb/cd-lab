# CD Lab Programs — Uppada Enos
**23XV1M0530 | CSE | 4th Year, 1st Semester**
**C R RAO AIMSCS / JNTU Hyderabad**

## Programs

| File | Question | Type | Topic |
|------|----------|------|-------|
| programs/q2_keywords.l | Q2 | LEX | Keywords, Numbers, Words |
| programs/q4_vowels.l | Q4 | LEX | Vowels & Consonants |
| programs/q6_count.l | Q6 | LEX | Lines, Words, Spaces, Chars |
| programs/q8_numbers.l | Q8 | LEX | +ve/-ve Integers & Fractions |
| programs/q3_rdp_asb.c | Q3 | C | RDP for S → aSb / ε |
| programs/q7_first_set.c | Q7 | C | FIRST Set Computation |
| programs/q1_rdp_expr.c | Q1 | C | RDP for Expression Grammar |
| programs/q5_opp.c | Q5 | C | Operator Precedence Parser |

## Deploy to Vercel

1. Install Vercel CLI: `npm i -g vercel`
2. Run: `vercel` inside this folder
3. Follow prompts — done

## Run LEX programs
```
lex filename.l
cc lex.yy.c -ll
./a.out
```

## Run C programs
```
gcc filename.c -o out
./out
```
