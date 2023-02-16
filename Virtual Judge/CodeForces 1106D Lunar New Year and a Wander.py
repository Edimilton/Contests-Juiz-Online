from queue import PriorityQueue

inf = float("inf")

class Grafo:
  class no():
    def __init__(self):
        self.vizinhos = []
  
  def __init__(self, n):
    self.n = n
    self.grafo = []
    for i in range(self.n):
      self.grafo.append(self.no())

  def add_aresta(self, u, v, peso):
    self.grafo[u].vizinhos.append((v,peso))
    self.grafo[v].vizinhos.append((u,peso))


def dijkstra(grafo, s):
    D = [inf]*grafo.n
    D[s] = 0
    visitado = [False]*grafo.n
  
    fila_prioridade = PriorityQueue()
    fila_prioridade.put((s, 0))
    visitado[s] = True

    while not fila_prioridade.empty():
      (vertice_escolhido, dist) = fila_prioridade.get()
      print(vertice_escolhido+1, end = " ")

      for adj, peso in grafo.grafo[vertice_escolhido].vizinhos:
        if not visitado[adj]:
          visitado[adj] = True
          fila_prioridade.put((adj, peso))
          D[adj] = peso  
    print()



if __name__=='__main__':

  vertices, arestas = input().split()
  vertices = int(vertices); arestas = int(arestas)

  g = Grafo(vertices)

  for i in range(arestas):
    u, v = input().split()
    g.add_aresta(int(u)-1, int(v)-1, max(u,v))

  dijkstra(g, 0)
