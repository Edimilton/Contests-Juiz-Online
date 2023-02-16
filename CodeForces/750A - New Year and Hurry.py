n,k = input().split()

minutos = 240 - int(k)
contador = 0
feitas = 0

while minutos >= contador and feitas <= int(n):
  feitas += 1
  contador = contador + (feitas * 5)

print(feitas-1)