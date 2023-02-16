#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

typedef pair<long long, long long> par_vertices;

struct UnionFind{
  long long *origens, *pos_conj;
  long long n;

  UnionFind(long long n){
    this->n = n;
    origens = new long long[n+1];
    pos_conj = new long long[n+1];

    for (long long i = 0; i <= n; i++) {
      pos_conj[i] = 0;
      origens[i] = i;
    }
  }

  long long find(long long u){
    if (u != origens[u])
      origens[u] = find(origens[u]);
    return origens[u];
  }

  void union_(long long u, long long v){
    u = find(u); 
    v = find(v);
    if(pos_conj[u] > pos_conj[v]) origens[v] = u;
    else if(pos_conj[v] > pos_conj[u]) origens[u] = v;
    else {origens[u] = v; pos_conj[v]++;}
  }
};


struct Grafo{
  long long vertice, aresta;
  vector< pair<long long, par_vertices> > arestas;

  Grafo(long long vertice, long long aresta){
    this->vertice = vertice;
    this->aresta = aresta;
  }
  
  void add_aresta(long long u, long long v, long long peso){
    arestas.push_back({peso, {u, v}});
  }

  long long Kruskal(){
    long long custo = 0; 
  
    sort(arestas.begin(), arestas.end());
      
    UnionFind vertices(vertice);
  
    vector< pair<long long, par_vertices> >::iterator aresta;
    
    for (aresta=arestas.begin(); aresta!=arestas.end(); aresta++){
      long long u = aresta->second.first;
      long long v = aresta->second.second;
  
      long long u_conj = vertices.find(u);
      long long v_conj = vertices.find(v);
  
      if(u_conj != v_conj){
          custo += aresta->first;
          vertices.union_(u_conj, v_conj);
      }
    }
  
    return custo;
  }
};

int main(){ 

  long long n_vert, cont=0;
    
  while(cin >> n_vert) {
    
    long long u, v, peso, linhas_antes = 0, linhas_depois, m_arest, m_ofert, m_arest_ant;
    Grafo grafo(maxn, maxn);
    
    if(cont>0){cout << endl;}
    cont++;
    
    m_arest = n_vert-1;  

    for(long long i=0;i<m_arest;i++){  
       cin >> u >> v >> peso;
       linhas_antes += peso;
    }

    cin >> m_ofert;

    for(long long i=0;i<m_ofert;i++){  
       cin >> u >> v >> peso;
       grafo.add_aresta(u-1,v-1,peso);
    }

    cin >> m_arest_ant;

    for(long long i=0;i<m_arest_ant;i++){  
       cin >> u >> v >> peso;
       grafo.add_aresta(u-1,v-1,peso);
    }

    linhas_depois = grafo.Kruskal();
    cout << linhas_antes << endl;
    cout << linhas_depois << endl;
  
  }
  return 0;
}