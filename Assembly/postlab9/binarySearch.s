; binarySearch.s, jp4hj, joon park
;
; Purpose : This file contains the implementation of the function
;           binary search
;
; Parameter 1 (in rdi) is the pointer to an int array
; Parameter 2 (in rsi) left of array
; Parameter 3 (in rdx) right of array
; Parameter 4 (in rcx) target

	global _binarySearch

	section .text

_binarySearch:

	xor	rax, rax	 ; zero out the return register


start:
	xor	r10, r10	 ; zero out mid

	cmp rsi, rdx	 ; while(low<=high)
	jg notfound

	add r10, rsi		;start + end
	add r10, rdx		
	shr r10, 1			;dividing by 2

	cmp [rdi+ 4*r10], ecx ; a[mid] < key
	jg greater
	je equal

	add r10, 1			;low = mid + 1
	mov rsi, r10

	jmp start


greater:
	sub r10, 1
	mov rdx, r10		;high = mid - 1

	jmp start

equal:
	mov rax, r10 	;returning mid -> might change r10
	ret


notfound:
	mov rax, -1
	ret