; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: gipark <gipark@student.42seoul.kr>         +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/01/15 12:08:51 by gipark            #+#    #+#              ;
;    Updated: 2021/01/20 01:04:05 by gipark           ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global	_ft_strlen
	extern	___error

; (rdi == s)
_ft_strlen:
	test rdi, rdi	; if (s < 0)
	js	_err		;	jump to _err
	mov	rax, 0		; rax = 0
	jmp _loop		; jump to loop

_loop:
	cmp BYTE [rdi + rax], 0			; rdi, rdi + rax, rdi + rax + rax... subtract 0
	je	_exit					; if [rcx + rax] - 0 equals 0, jump to exit
	inc	rax						; rax++
	jmp _loop					; jump to loop again

_err:
	push	rax				; sub rsp, rax's data size	; mov [rsp], rax
	call	___error		; rax = _error
	pop		rdx				; mov rdx, [rsp]	; add rsp, rax's data size
	mov		[rax], rdx		; *rax = rdx
	mov		rax, -1			; rax = -1
	ret
	
_exit:
	ret			; return rax
