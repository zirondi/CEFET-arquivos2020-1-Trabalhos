'''
Quest˜ao 1 Escreva um programa na sua linguagem de programa¸c˜ao de preferˆencia que
conte o n´umero de palavras e linhas de um arquivo texto, com o nome passado pelo
argumento do comando de linha.
'''
import sys

if len(sys.argv) != 2:
	print ("USO %s [foo.txt]" % sys.argv[0])
	quit()

f = open(sys.argv[1], 'r')

textList = f.readlines()

print("Número de linhas: ", len(textList))

num = 0
for line in textList:
    num = num + line.count(' ')

print("Número de espaços: ",num)
    

