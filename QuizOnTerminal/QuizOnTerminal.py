import time
import os

def explicacion(num, file3):
    lineas = list()
    exp = list()
    for line in file3:
        if line.startswith(num):
            lineas.append(line)
    index = lineas.index(num + ' Explicacion:\n')
    lineas = lineas[index:]
    for i in lineas:
        i = i.replace(num + ' ','',1)
        exp.append(i)
    exp = ''.join(exp)
    return(exp)

def respuesta(answer, num, file2):
    for line in file2:
        if num in line and 'Respuesta=' in line:
            line = line.split()
            if answer == line[2]:
                return('CORRECTO\n')
            else:
                return('INCORRECTO\n')

def pregunta(num, file):
    lineas = list()
    preg = list()
    for line in file:
        if line.startswith(num):
            lineas.append(line)
    for i in lineas:
        if i.startswith(num) and 'Respuesta=' in i:
            pre = i
    index = lineas.index(pre)
    lineas = lineas[:index]
    for i in lineas:
        i = i.replace(num,'',1)
        preg.append(i)
    preg = ''.join(preg)
    return(preg)

count_c = 0
count_i = 0
x = True
validas = ['1', '2', '3', '4']

#Menu
print('Escoga un tema usando un numero de los temas de matemáticas por estudiar:\n1. Aritmética y Algebra\n2. Geometría\n3. Funciones\n4. Combinatoria y Probabilidad')
while x == True:
    opcion = input()
    if opcion in validas:
        x = False
    else:
        print('Porfavor seleccione un numero del 1 al 4 correspondiendo al tema')
        continue


#Aritmetica y Algebra

if opcion == '1':
    arch = os.path.exists('Aritmetica_Algebra.txt')
    if arch == False:
        print('No encontre el archivo de "Aritmetica_Algebra.txt"')
        quit()
    print('\nBienvenido a Aritmetica y Algebra\n')
    for i in range(1,5):
        y = True
        file = open('Aritmetica_Algebra.txt')
        file2 = open('Aritmetica_Algebra.txt')
        file3 = open('Aritmetica_Algebra.txt')
        print(pregunta(str(i), file))
        while y == True:
            answer = input('Respuesta: ').lower()
            if answer not in ('a', 'b', 'c', 'd'):
                try:
                    int(answer)
                    print('Ponga una respuesta valida')
                    continue
                except:
                    print('Ponga una respuesta valida')
                    continue
            else:
                y = False
        checar = respuesta(answer, str(i), file2)
        resexp = explicacion(str(i), file3)
        file.close()
        file2.close()
        file3.close()
        print(checar)
        if checar == 'CORRECTO\n':
            count_c += 1
        else:
            count_i += 1
            print(resexp)
        time.sleep(2)
    print('Gracias por participar')
    print('Correctos: ', count_c)
    print('Incorrectos: ', count_i)

#Geometria
if opcion == '2':
    arch = os.path.exists('Geometria.txt')
    if arch == False:
        print('No encontre el archivo de "Geometria.txt"')
        quit()
    print('\nBienvenido a Geometria\n')
    for i in range(1,5):
        y = True
        file = open('Geometria.txt')
        file2 = open('Geometria.txt')
        file3 = open('Geometria.txt')
        print(pregunta(str(i), file))
        while y == True:
            answer = input('Respuesta: ').lower()
            if answer not in ('a', 'b', 'c', 'd'):
                try:
                    int(answer)
                    print('Ponga una respuesta valida')
                    continue
                except:
                    print('Ponga una respuesta valida')
                    continue
            else:
                y = False
        checar = respuesta(answer, str(i), file2)
        resexp = explicacion(str(i), file3)
        file.close()
        file2.close()
        file3.close()
        print(checar)
        if checar == 'CORRECTO\n':
            count_c += 1
        else:
            count_i += 1
            print(resexp)
        time.sleep(2)
    print('Gracias por participar')
    print('Correctos: ', count_c)
    print('Incorrectos: ', count_i)

#Funciones
if opcion == '3':
    arch = os.path.exists('Funciones.txt')
    if arch == False:
        print('No encontre el archivo de "Funciones.txt"')
        quit()
    print('\nBienvenido a Funciones\n')
    for i in range(1,5):
        y = True
        file = open('Funciones.txt')
        file2 = open('Funciones.txt')
        file3 = open('Funciones.txt')
        print(pregunta(str(i), file))
        while y == True:
            answer = input('Respuesta: ').lower()
            if answer not in ('a', 'b', 'c', 'd'):
                try:
                    int(answer)
                    print('Ponga una respuesta valida')
                    continue
                except:
                    print('Ponga una respuesta valida')
                    continue
            else:
                y = False
        checar = respuesta(answer, str(i), file2)
        resexp = explicacion(str(i), file3)
        file.close()
        file2.close()
        file3.close()
        print(checar)
        if checar == 'CORRECTO\n':
            count_c += 1
        else:
            count_i += 1
            print(resexp)
        time.sleep(2)
    print('Gracias por participar')
    print('Correctos: ', count_c)
    print('Incorrectos: ', count_i)

#Combinacion y Prob
if opcion == '4':
    arch = os.path.exists('Comb_Prob.txt')
    if arch == False:
        print('No encontre el archivo de "Comb_Prob.txt"')
        quit()
    print('\nBienvenido a Combinación y Probabilidad\n')
    for i in range(1,5):
        y = True
        file = open('Comb_Prob.txt')
        file2 = open('Comb_Prob.txt')
        file3 = open('Funciones.txt')
        print(pregunta(str(i), file))
        while y == True:
            answer = input('Respuesta: ').lower()
            if answer not in ('a', 'b', 'c', 'd'):
                try:
                    int(answer)
                    print('Ponga una respuesta valida')
                    continue
                except:
                    print('Ponga una respuesta valida')
                    continue
            else:
                y = False
        checar = respuesta(answer, str(i), file2)
        resexp = explicacion(str(i), file3)
        file.close()
        file2.close()
        file3.close()
        print(checar)
        if checar == 'CORRECTO\n':
            count_c += 1
        else:
            count_i += 1
            print(resexp)
        time.sleep(2)
    print('Gracias por participar')
    print('Correctos: ', count_c)
    print('Incorrectos: ', count_i)