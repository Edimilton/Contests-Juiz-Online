def main():

  n = int(input())
  entrada = [int(x) for x in input().split()]

  neg = 0
  zeros = 0

  result = 0

  for i in range(n):
    
      if entrada[i] > 0:
          result += entrada[i] - 1
      elif entrada[i] < 0:
          neg += 1
          result += abs(entrada[i]) - 1
      else:
          zeros += 1
          result += 1

  if neg % 2 and zeros == 0:
      result += 2

  print(result)

if __name__ == '__main__':
	main()