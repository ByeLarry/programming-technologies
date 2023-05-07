.code

MYD proc
;аргументы функции
;RCX - start
;RDX - end
;[R8] - mat, 
;R9
;return RAX

;инициализация локальных переменных
LOCAL dist[6]:dword 
LOCAL visited[6]:dword
LOCAL s:dword
LOCAL e:dword
LOCAL u:dword
mov s, ecx
mov e, edx

mov edx, 0
init:
    cmp edx, 6
    jge endinit
    mov [dist + rdx*4], 99999
    mov [visited + rdx*4], 0
    inc edx
    jmp init
endinit:

mov eax, s
mov [dist + rax * 4], 0

;запуск главного цикла
mov ecx, 0   
for1:
    cmp ecx, 6 
    jge endfor1  
    mov u, 100
    mov edx, 0
    for2:
        cmp edx, 6
        jge endfor2

        ; Проверяем visited[j]
        mov eax, [visited + rdx*4]
        cmp eax, 0 
        jne endif1 
        mov eax, u 

        ;u == 100
        cmp eax, 100 
        je then1 
        mov eax, [dist + rdx*4]
        mov ebx, u
        mov ebx, [dist + rbx*4]

        ; dist[edx] < dist[u]
        cmp eax, ebx 
        jge endif1 

        ; Если оба условия выполняются
        then1:
        mov eax, edx ; Загружаем j в регистр eax
        mov u, eax ; Присваиваем u значение eax

        endif1:
        inc edx
        jmp for2
    endfor2:
    mov eax, u
    mov [visited + rax*4], 1

    ;цикл, устанавливающий значения в массиве dist
    mov r12d,0
    for3:
        cmp r12d, 6 
        jge endfor3

        ;if (matrix[u][v] > 0)
        ;в r15d формируется адресс элемента матрицы matrix[eax][r12d]
        ;умножаем 3 раза на 8 потому что компилятор masm разрешает умножать только на 1, 2, 4, 8
        lea r15d, [eax * 8]
        lea r15d, [r15d + eax * 8]
        lea r15d, [r15d + eax * 8]
        lea r15d, [r15d + r12d * 4]

        mov r9d, [r8d + r15d]
        cmp r9d,0
        jle antithan2

        
        add r9d, [dist + rax*4]
        
        ;if (alt < dist[v])
            mov r10d, [dist + r12*4]
            cmp r9d, r10d
            jge antithan2
            mov [dist + r12*4], r9d 
            
        ;if (alt < dist[v])
        antithan2: 

        ;if (matrix[u][v] > 0)
        inc r12d   
        jmp for3
    endfor3:
    inc ecx   
    jmp for1  
endfor1:

;формируется возврат из функции
;возвращаемое значение должно быть в регистре RAX
;в данном случае возращается кротчайший путь из S до E
mov ebx, e
mov eax, [dist + rbx*4]
ret
MYD endp
end