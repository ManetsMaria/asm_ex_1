.486
.model flat, stdcall                    
option casemap :none

include windows.inc     ; always first

include masm32.inc
include gdi32.inc
include user32.inc
include kernel32.inc

includelib masm32.lib
includelib gdi32.lib
includelib user32.lib
includelib kernel32.lib

.data
    szStr               db  "bbbb    ytr kllk  popy$", 13, 10, 0
    szAnswer            db  30 dup(' ')
    buf                 db  300 dup(' ')
    maxSize             dd 0
    szGoodBye           db  13, 10, "Press ENTER to continue...", 13, 10, 0
.data?
    flag                dd ?
.code

CountSymb proc

    mov flag, esi
    mov eax, 0
    mov ecx, 0
    beg:
    mov bl, byte ptr[esi]
    cmp bl, '$'
    je end_end_
    cmp bl, ' '
    je end_end_
    add eax, 1
    add esi, 1
    mov edi, esi
    cop:
    mov dl, byte ptr[edi]
    cmp dl, '$'
    je beg
    cmp dl, ' '
    je beg
    cmp dl, bl
    je equal_
    add edi, 1
    jmp cop
    equal_:
    add ecx, 1
    end_end_:
    sub eax, ecx
    ret

CountSymb endp

MainProc	proc
            lea esi, szStr
            start:
            mov bl, byte ptr[esi]
            cmp bl, '$'
            je end_
            cmp bl, ' '
            je go_
            jmp beg_word
            go_:
            add esi, 1
            add ecx, 1
            jmp start
            beg_word:
            call CountSymb
            cmp eax, maxSize
            jg change_
            jmp start
            change_:
            mov maxSize, eax
            mov esi, flag
            lea edx, szAnswer
            ans:
            cmp edi, esi
            je end_change
            mov bl, byte ptr[esi]
            mov [edx], bl
            add edx, 1
            add esi, 1
            jmp ans
            end_change:
            jmp start
            end_:
            invoke  StdOut, addr szAnswer
            ;invoke  StdOut, addr szGoodBye
            invoke  StdIn, addr buf, 300
            invoke  ExitProcess, 0
MainProc    endp

end MainProc












