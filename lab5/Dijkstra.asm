
.data
dist DWORD 6 dup(99999)
visited dword 6 dup(0)
s dword 1 dup(0)
e dword 1 dup(0)
u dword  1 dup(0)
.code

MYD proc
;extern "C" int Sum(int start, int end)
;RCX - start
;RDX - end
;R8 - mat, [r8]- first elem in mat
;R9
;return RAX


mov [dist], 99999
mov [dist+4], 99999
mov [dist+8], 99999
mov [dist+12], 99999
mov [dist+16], 99999
mov [dist+20], 99999

mov [visited], 0
mov [visited+4], 0
mov [visited+8], 0
mov [visited+12], 0
mov [visited+16], 0
mov [visited+20], 0

mov eax, ecx
mov [dist + eax * 4], 0
mov [s], ecx
mov [e], edx

mov ecx, 0   
for1:
    cmp ecx, 6 
    jge endfor1  
    mov [u], 100
    mov edx, 0
    for2:
        cmp edx, 6
        jge endfor2
        ;условие---------------------
        ; Проверяем visited[j]
        mov eax, [visited + edx*4] 
        cmp eax, 0 
        jne endif1 

        mov eax, u 
        cmp eax, 100 
        je then1 

        ; dist[edx] < dist[u]
        mov eax, [dist + edx*4] 
        mov ebx, [u]
        mov ebx, [dist + ebx*4] 
        cmp eax, ebx 
        jge endif1 

        ; Если оба условия выполняются
        then1:
        mov eax, edx ; Загружаем j в регистр eax
        mov [u], eax ; Присваиваем u значение eax

        endif1:

        ;условие---------------------
        inc edx
        jmp for2
    endfor2:
    ;перед 3 циклом 
    mov eax, [u]
    mov [visited + eax*4], 1
    ;for3-----------------------------
    mov r12d,0
    for3:
        cmp r12d, 6 
        jge endfor3
        ;if (matrix[u][v] > 0)----------не_точно-\/-------------
        mov r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, eax
        add r15d, r12d
        add r15d, r12d
        add r15d, r12d
        add r15d, r12d
        mov r9d, [r8d + r15d]; matrix[eax][r12d]
        cmp r9d,0
        jle antithan2
        add r9d, [dist + eax*4] ;alt
        ;if (alt < dist[v])---------------------- 
            mov r10d, [dist + r12d*4]
            cmp r9d, r10d
            jge antithan2
            mov [dist + r12d*4], r9d
            
        ;if (alt < dist[v])----------------------
        antithan2:
             
        ;if (matrix[u][v] > 0)----------------------------
        inc r12d   
        jmp for3
    endfor3:
    ;for3-----------------------------
    inc ecx   
    jmp for1  
endfor1:
mov ebx, [e]
mov eax, [dist + ebx*4]

ret
MYD endp
end