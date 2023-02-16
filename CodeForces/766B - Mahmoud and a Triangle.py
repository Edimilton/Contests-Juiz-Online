def esquerda(pos):
  return (2 * pos) + 1

def direita(pos):
  return 2 * (pos + 1)

def pai(pos):
  return int((pos - 1)/ 2)

def borbulhar(vetor, pos):
  p = pai(pos)
  while pos > 0 and vetor[pos] > vetor[p]:
    vetor[pos], vetor[p] = vetor[p], vetor[pos]
    pos = p
    p = pai(pos)

def gotejar(vetor, tamanho, pos):
  while pos >= 0:
    controle = -1
    dir = direita(pos)
    esq = esquerda(pos)
    
    if dir < tamanho and vetor[dir] > vetor[pos]:
      if vetor[esq] > vetor[dir]:
        controle = esq
      else:
        controle = dir
        
    else:
      if esq < tamanho and vetor[esq] > vetor[pos]:
        controle = esq
        
    if controle >= 0 :
      vetor[controle],vetor[pos] = vetor[pos], vetor[controle]
    pos = controle
    
  return vetor

def insere(vetor, item):
  vetor.append(item)
  vetor = borbulhar(vetor, len(vetor) - 1)
  return True

def novaHeap(vetor):
  heap = []
  for i in range(len(vetor)):
    insere(heap,int(vetor[i]))
  return heap

def heapsort(vetor, tamanho):
  while tamanho > 1:
    vetor[tamanho -1], vetor[0] = vetor[0], vetor[tamanho -1] 
    tamanho -= 1
    vetor = gotejar(vetor, tamanho, 0)
  return vetor

def main():
  n = int(input())
  a = input().split()

  heap = heapsort(novaHeap(a), n)
  i = 0
  
  while n > 2:
    if heap[i] + heap[i+1] > heap[i+2]:
      return print("YES")
    i += 1
    n -=1
  print("NO")

if __name__ == '__main__':
	main()
