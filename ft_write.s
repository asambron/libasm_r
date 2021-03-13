section .text
	global ft_write			
	extern __errno_location	

ft_write:				
	push rbp
	mov rbp, rsp
	mov rax, 1		
	syscall		
	or rax, rax	
	jl _errno
	jmp _end

_errno:		
	neg rax
	push rax
	call __errno_location
	mov rbx, rax		
	pop rax			
	mov [rbx], rax
	mov rax, -1	
	jmp _end

_end:
	pop rbp
	ret
