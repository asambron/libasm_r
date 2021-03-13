section .txt
	global ft_strcmp

ft_strcmp:
	push rbp
	mov rbp, rsp
	xor rax, rax
	xor rbx, rbx
	xor cx, cx
	xor dx, dx

_loop:
	mov cl, [rdi + rbx]
	mov dl, [rsi + rbx]
	or cl, cl
	jz _ret_value
	or dl, dl
	jz _ret_value
	cmp cl, dl
	jne _ret_value
	inc rbx
	jmp _loop

_ret_value:
	sub cx, dx
	jl _negative
	ja _postive
	jmp _equal

_negative:
	mov rax, -1
	pop rbp
	ret

_postive:
	mov rax, 1
	pop rbp
	ret

_equal:
	mov rax, 0
	pop rbp
	ret
