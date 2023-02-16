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
  vector< pair<double, par_vertices> > arestas;

  Grafo(long long vertice, long long aresta){
    this->vertice = vertice;
    this->aresta = aresta;
  }
  
  void add_aresta(long long u, long long v, double peso){
    arestas.push_back({peso, {u, v}});
  }

  double Kruskal(){
    double custo = 0; 
  
    sort(arestas.begin(), arestas.end());
    
    UnionFind vertices(vertice);
  
    vector< pair< double, par_vertices> >::iterator aresta;
    
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


double distancia(pair< double, double> A, pair< double, double> B){
  double c = A.first - B.first;
  double d = A.second - B.second;
  return sqrt(c * c + d * d);
}



int main(){   
    int n_casos;
    cin >> n_casos;

    for(int k=0; k<n_casos;k++){

      if(k!=0) cout << endl;
      
      long long n_vert;
      double a, b;
      vector< pair<double, double> > vertices;
      
      cin >> n_vert;
      
      for(long long i=0; i<n_vert;i++){
        cin >> a >> b;
        vertices.push_back({a, b});
      } 

      long long n_arest = n_vert*n_vert;
      Grafo grafo(n_vert, n_arest);

      for(long long i=0; i<n_vert; i++){
        for(long long j=i+1; j<n_vert; j++){
          grafo.add_aresta(i, j, distancia(vertices[i],vertices[j]));
        }
      }

      printf("%.2lf\n",grafo.Kruskal());

    }

    return 0;
}