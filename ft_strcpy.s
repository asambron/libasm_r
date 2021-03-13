section .text
	global ft_strcpy

ft_strcpy:
	push rbp
	mov rbp, rsp
	mov rax, rdi

_loop:
	cmp [rsi], byte 0
	jz _loop_end
	movsb
	jmp _loop

_loop_end:
	mov byte [rdi], 0
	pop rbp
	ret
