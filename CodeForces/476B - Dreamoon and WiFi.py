def possib_corretas(esperado, entrada, icognitas):
  if icognitas == 0:
    if entrada == esperado:
      return 1
    return 0
  return possib_corretas(esperado, entrada+1, icognitas-1) + possib_corretas(esperado, entrada-1, icognitas-1)


def main():

    maismenos = input()
    maismenosicog = input()
    esperado = 0
    entrada = 0
    icognitas = 0

    for c in maismenos:
      if c =='+':
        esperado += 1
      else:
        esperado -= 1
  
    for c in maismenosicog:
      if c == '+':
        entrada += 1
      elif c == '-':
        entrada -= 1
      else:
        icognitas += 1
          
    corretas = possib_corretas(esperado, entrada, icognitas)
  
    probabilidade = corretas/(2**icognitas)

    print(probabilidade)

if __name__ == '__main__':
	main()