#include<bits/stdc++.h>
using namespace std;

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
    long long n_vert, n_ofert;
    cin >> n_vert >> n_ofert;
  
    long long n_aresta = n_vert + n_ofert;
    long long menor_vertice = 9999999999999;
    long long indice = 0;
    long long vertices[n_vert];
    long long u, v, peso;
  
  
    for(long long i=0; i<n_vert; i++){
        cin >> vertices[i];
        if(vertices[i]<menor_vertice){
          menor_vertice = vertices[i];
          indice = i;
        } 
    }

    Grafo grafo(n_vert, n_aresta);
  
    for(long long i=0; i<n_vert; i++){
      if(indice != i) grafo.add_aresta(indice, i, vertices[indice]+vertices[i]);
    }
  
    for(long long i=0;i<n_ofert;i++){  
       cin >> u >> v >> peso;
       if(vertices[indice] + vertices[u-1] > peso || vertices[indice] + vertices[v-1] > peso) grafo.add_aresta(u-1,v-1,peso);
    }
       
    long long custo = grafo.Kruskal();
    cout << custo << endl;

    return 0;
}