; threexplusone.s
;
; Purpose : This file contains the implementation of the Collatz Conjecture
;           
;
; Parameter 1 (in rdi) is the number
;  

	global threexplusone

	section .text

threexplusone:
	xor rax, rax

start:

	cmp rdi, 1			;basecase when x == 1 -> number of steps = 0
	je basecase

	test rdi, 1 		;testing whether register is odd or even
	jz even

	imul rdi, 3			;if it is odd...
	add rdi, 1
	inc rax
	call start

	ret


even:

	shr rdi, 1			;divide by 2;
	inc rax				;increment counter by 1
	call start

	ret

basecase:
	ret

