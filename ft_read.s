section .text
	global ft_read          
	extern __errno_location 

ft_read:				
	push rbp
	mov rbp, rsp
	mov rax, 0		
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
