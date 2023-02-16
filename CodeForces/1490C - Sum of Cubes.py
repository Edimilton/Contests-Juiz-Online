def soma_de_cubos(solucao,teto):
  solo = 1
  while solo <= teto:
    meio = (solo + teto) // 2
    a = meio**3
    if a == solucao: return True
    elif a > solucao: teto = meio - 1
    else: solo = meio + 1

  return False

def main():
  t = int(input())
  resposta = []
  while t > 0:
    x = int(input())
    b = 1
    
    while b**3 <= x:
      solucao = x - b**3
      if soma_de_cubos(solucao,int(x**(1/3))):
        resposta.append("YES")
        break
      b += 1 
      
    if b**3 > x:
      resposta.append("NO")
    
    t -= 1
    
  for yes_no in resposta:
    print(yes_no)

if __name__ == '__main__':
	main()
