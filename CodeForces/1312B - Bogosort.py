def mergeSort(lista):
    if len(lista) > 1:
        meio = int(len(lista)/2)

        lista_esq = lista[:meio]
        lista_dir = lista[meio:]

        mergeSort(lista_esq)
        mergeSort(lista_dir)

        intercala(lista, lista_esq, lista_dir)
      
    return lista

def intercala( lista, lista_esq, lista_dir):
  i = 0
  j = 0
  k = 0

  while i < len(lista_esq) and j < len(lista_dir):
    esq = lista_esq[i]
    dir = lista_dir[j]
    if esq >= dir:
        lista[k]=lista_esq[i]
        i += 1
    else:
        lista[k]=lista_dir[j]
        j += 1
    k += 1

  while i < len(lista_esq):
    lista[k]=lista_esq[i]
    i += 1
    k += 1

  while j < len(lista_dir):
    lista[k]=lista_dir[j]
    j += 1
    k += 1

def main():
  listas = []
  t = int(input())
  
  while t > 0:
    n = int(input())
    a = input().split()
    lista = []
    for i in range(n):
        lista.append(int(a[i]))
    listas.append(mergeSort(lista))
    t -= 1

  for lista in listas:
    ultimo = lista.pop()
    for num in lista:
     print(num,end=" ")
    print(ultimo)


if __name__ == '__main__':
	main()

