.386
PUBLIC @task1@8
.model flat
.code
@task1@8 proc
    push ebp
    mov ebx, edx
	mov eax, ecx
	mov ebp, eax
	mov esi, 0
	mov ecx, 0
	gr1:
		cmp esi, ebx
        je end_
		add esi, 1
		mov edx, [eax + 4*esi]
		sub esi, 1
		cmp [eax + 4*esi], edx
		jl beg
		add esi, 1
		jmp gr1
	beg:
		mov edi, [eax+4*esi]
		mov [eax+4*esi], edx
		add esi, 1
		mov [eax+4*esi], edi
		jmp gr1
	end_:
		cmp ecx, ebx
		je end_end_
		mov esi, 0
		add ecx, 1
		jmp gr1
	end_end_:
		mov ecx, eax
		mov esi, 2
		mov eax, ebx
		cdq
		idiv esi
		mov esi, eax
		mov eax, ecx
        mov esi, [eax+4*esi]
		mov ecx, ebx
		sub ecx, 1
	gr3:
	    mov edx, [ebp+4*ecx]
		cmp esi, edx
		je end_end_end_
		loop gr3
	end_end_end_:
		mov [eax],ecx
		pop ebp
	ret
@task1@8 endp
end 