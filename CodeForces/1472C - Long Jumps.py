def longJumps(result):
  
    n = int(input())
    entrada = [int(x) for x in input().split()]
    maior_pulo = [0]*n
  
    for i in range(n-1,-1,-1):
        indice_atual = i
        maior_pulo[i] = entrada[i]
        indice_atual += entrada[i]
        if indice_atual < n:
            maior_pulo[i] += maior_pulo[indice_atual]
      
    result.append(max(maior_pulo))


def main():

    casos = int(input())
    result = []
    for i in range(casos):
        longJumps(result)
    for i in range(casos):
      print(result[i])


if __name__ == '__main__':
	main()