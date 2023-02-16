def find(origens, u):
  if origens[u] != u:
    origens[u] = find(origens, origens[u])
  return origens[u]

def union(origem, pos_conj, u, v):
  if pos_conj[u] < pos_conj[v]: origem[u] = v
  elif pos_conj[u] > pos_conj[v]: origem[v] = u
  else:
    origem[v] = u
    pos_conj[u] += 1


def Kruskal(vertices, arestas, arestas_G, n):
      
  arestas = sorted(arestas, key=lambda item: item[2])
  arestas = arestas_G + arestas
  #print(arestas)
  
  custo = 0
  origens = []
  pos_conj = []

  for vertice in range(n):
    origens.append(vertice)
    pos_conj.append(0)

  for u, v, peso in arestas:
    u_orig = find(origens, u)
    v_orig = find(origens, v)

    if u_orig != v_orig:
      custo += peso
      union(origens, pos_conj, u_orig, v_orig)
        
  return custo
 

if __name__=='__main__':
  
  n_vertices = int(input())
  
  valor = [0]*n_vertices
  cor = [""]*n_vertices
  arestas = []
  arestas_G = []
  vertices = []
  
  for i in range(n_vertices):
    valor[i], cor[i] = input().split()
    valor[i] = int(valor[i])
    vertices.append(i)

  ind_G, ind_R, ind_B, seccao = -1, -1, -1, False

  for i in range(n_vertices):  
    #print(i, valor[i], cor[i])
    
    if cor[i] == "G" and ind_G != -1:
      arestas_G.append([ind_G, i,abs(valor[ind_G]-valor[i])])
      ind_G = i
      seccao = True
    elif cor[i] == "G" and ind_G == -1: ind_G = i
    if cor[i] == "G" and ind_R != -1:
      arestas.append([ind_R, i,abs(valor[ind_R]-valor[i])])
      ind_G = i
      ind_R = -1
    if cor[i] == "G" and ind_B != -1:
      arestas.append([ind_B, i,abs(valor[ind_B]-valor[i])])
      ind_G = i
      ind_B = -1
    if seccao: ind_R = -1; ind_B = -1; seccao = False
      
      
    if cor[i] == "R" and ind_R != -1:
      arestas.append([ind_R, i,abs(valor[ind_R]-valor[i])])
      ind_R = i
    elif cor[i] == "R" and ind_G != -1:
      arestas.append([ind_G, i,abs(valor[ind_G]-valor[i])])
      ind_R = i
    elif cor[i] == "R" and ind_R == -1: ind_R = i

    
    if cor[i] == "B" and ind_B != -1:
      arestas.append([ind_B, i,abs(valor[ind_B]-valor[i])])
      ind_B = i
    elif cor[i] == "B" and ind_G != -1:
      arestas.append([ind_G, i,abs(valor[ind_G]-valor[i])])
      ind_B = i
    elif cor[i] == "B" and ind_B == -1: ind_B = i
    #print(arestas)
      
    
  if ind_G == -1 and ind_R != -1 and ind_B != -1:
    menor_dist_R_B = float("inf")
    ind_R = -1
    ind_B = -1

    for i in range(n_vertices):  
      if cor[i] == "R":
        if i > -1 and cor[i-1] == "B":
          if abs(valor[i-1]-valor[i]) < menor_dist_R_B:
            menor_dist_R_B = abs(valor[i-1]-valor[i])
            ind_R = i
            ind_B = i-1
        if i < (n_vertices-1) and cor[i+1] == "B":
          if abs(valor[i]-valor[i+1]) < menor_dist_R_B:
            menor_dist_R_B = abs(valor[i]-valor[i+1]) 
            ind_R = i
            ind_B = i+1

    arestas_G.append([ind_R, ind_B, menor_dist_R_B])
    
  custo = Kruskal(vertices, arestas, arestas_G, n_vertices)
  print(custo) 