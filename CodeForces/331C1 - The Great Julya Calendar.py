def converte(c):
  return (ord(c) - 48)

def main():

  n = int(input())
  
  infinito = float("inf")
  minima_operacao = [infinito for i in range(n + 1)]
  minima_operacao[0] = 0

  for i in range(1,n+1):
      for c in str(i):    
          minima_operacao[i] = min(minima_operacao[i], minima_operacao[i - converte(c)] + 1)

  print(minima_operacao[n])

if __name__ == '__main__':
	main()