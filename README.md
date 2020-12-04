# Acram-alpha
 Tool for differentiating expressions and printing results in LaTex
* pdflatex is required
### Input format:
* Input file(file with expression) and output file names should be given as arguments to the program
* Default input file name is input.txt, default output file name is output.txt.
* If there is only one file name it counts as input file. Output file name is default.
* If there are no file names input file and output file names are default. 
##### Input expression format:
Expression in standart notation. 
* Variables' names - length is lesser or equal than 99 characters, 
characters are latin characters from a to z 
and digits from 0 to 9. First character is latin. Examples: x1, er3.
* Numbers - real. Format is standard.
Examples: 2, 4.5, -3, -4.8.
* Mathematical operators:
  * addition (+)
  * multiplication (*)
  * subtraction (-)
  * division (/)
  * exponentiation (^)
* Functions:
  * sine (sin)
  * cosine (cos)
  * tangent (tan)
  * natural logarithm (ln)
  * exponent (exp)

* Expression example: sin(x^2) + cos(y*3)^4 - z.
### Output format:
 .tex file with LaTex code, compilation files and .pdf files with derivatives of this expression for all variables.
