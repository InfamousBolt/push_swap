# push_swap
>Description
A program to sort a stack using limited number of operations.
![Rules](https://user-images.githubusercontent.com/47386839/147467651-b8834b84-0bcd-45e7-937a-17bc33edd7d2.png)
![RulesContinued](https://user-images.githubusercontent.com/47386839/147467664-061c109f-ef2f-422e-ba24-98a3cea2e53d.png)

>How to use
1. Clone the repo.
2. Get into the cloned repo.
3. Use `make` to compile all the files:
![make](https://user-images.githubusercontent.com/47386839/147468321-a8fac7f2-5544-4474-aa06-827c76f4e3bb.png)
5. Run `./push_swap` with numbers of the unsorted stack as args:
![run](https://user-images.githubusercontent.com/47386839/147468346-effdd980-97e4-402e-88dc-060709a232f9.png)

>Restrictions
In case of error, program must display *Error* followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.

>Output interpretation
The program outputs a list of instruction on each new line on how to sort the unsorted stack.
