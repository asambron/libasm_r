section .text
	global ft_strlen

ft_strlen:
	push rbp
	mov rbp, rsp
	xor rcx, rcx

_loop:
	cmp [rdi], byte 0
	jz _end
	inc rcx
	inc rdi
	jmp _loop

_end:   
	mov rax, rcx
	pop rbp
	ret
