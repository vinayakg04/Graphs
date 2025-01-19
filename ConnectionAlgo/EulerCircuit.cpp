class Solution{
public:

string EularCircuit(int V,vector<int> adj[]){
  int odddegreecount=0;
  for(int i=0;i<V;i++){
    if(adj[i].size()%2!=0){
      odddegreecount++;
    }
  }

  if(oddegreecount>2) return "NOT any Graph";
  if(odddegreecount==2) return "Semi Eulerian Graph";
  return "Eulerian Graph";
}

}
