section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	cmp rdi, 0x0
	jz _err
	push rbp   
	mov rbp, rsp
	mov r12, rdi
	call ft_strlen
	inc rax      
	mov rdi, rax 
	call malloc
	or rax, rax 
	jz _err
	mov rdi, rax 
	mov rsi, r12 
	call ft_strcpy
	pop rbp      
	ret

_err:
	xor rax, rax 
	pop rbp     
	ret
