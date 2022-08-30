// This program shows how C++-based file I/O works.
// It will open a file, read in the first two strings, and print them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include "Vertex.h"
using namespace std;

// we want to use parameters

vector<Vertex*> adjacencylist;
vector<string> holder;
vector<string> different;
map<string, int> matching;
void topsort(vector<Vertex*> adjacencylist, map<string, int> m);
void helper(map<string, int> m, Vertex* v);

int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }


    // read in two strings
    string s1, s2;
    list<Vertex*> l;

    while(file >> s1 >> s2 && s1 != "0" && s2 != "0") {
        holder.push_back(s2);
    }

    file.clear();
    file.seekg(0, file.beg);

    while(file >> s1 >> s2 && s1 != "0" && s2 != "0") {
     Vertex* v = new Vertex(); 
     Vertex* w = new Vertex();
     bool isNew = true; 
     for (int i = 0; i < different.size(); i++){
        if(different.at(i) == s1){
            isNew = false;
        }
    }

    v->name = s1;
    w -> name = s2;


    for(int i = 0; i < holder.size(); i++){ 
        if(holder.at(i) == s1){
            int counter = count(holder.begin(), holder.end(), holder.at(i));
            v->indegree = counter;
        }
        if(holder.at(i) == s2){
            int counter = count(holder.begin(), holder.end(), holder.at(i));
            w->indegree = counter;
        }
    }

    matching[w ->name] = w -> indegree; //filling up the map






    if(isNew){
        different.push_back(s1);
        v->edges.push_back(w);
        adjacencylist.push_back(v);
    }
    else{
        for(int i = 0; i < adjacencylist.size(); i++){
            if(adjacencylist.at(i) -> name == v -> name){
                adjacencylist.at(i)->edges.push_back(w);
            }
        }
    }





}

    // map<string, int>::iterator it; 
    // for(it = matching.begin(); it != matching.end(); it++ ){
    //     cout << "String: "<<  it ->first << endl;
    //     cout << "int: " << it -> second << endl;
    // }
topsort(adjacencylist,matching);

// for(int i = 0; i < adjacencylist.size(); i++){
//     cout << "Verticies: " << adjacencylist.at(i)-> name << " Indegree: " << adjacencylist.at(i)->indegree<<  endl;
//     for(int j = 0; j < adjacencylist.at(i) -> edges.size();j++ ){
//         cout << "Edges: " << adjacencylist.at(i) -> edges.at(j) -> name << " Indegree: " << adjacencylist.at(i) -> edges.at(j) -> indegree << endl ;
//     }
// }





file.close();


return 0;
}

void topsort(vector<Vertex*> adjlist, map<string, int> m){
    string s = "";
    bool isDone = true ;
    queue<Vertex*> q;
    vector<string> result;

    while(isDone ){
        for (int i = 0; i < adjlist.size(); i++ ){
            helper(m, adjlist.at(i));
        if(adjlist.at(i) -> indegree == 0){ //checking for indegree 0 
            auto iter = find(result.begin(),result.end(),adjlist.at(i) -> name);
            if(iter == result.end()){
                result.push_back(adjlist.at(i) -> name);
            }


            for(int k = 0; k < adjlist.at(i) -> edges.size(); k++){ //looping through the edges
             helper(m, adjlist.at(i) -> edges.at(k));
             if(adjlist.at(i) -> edges.at(k) -> indegree != 0){
                adjlist.at(i) -> edges.at(k) -> indegree--; //subtracting by 1 each time
            }
            if(m.find(adjlist.at(i) -> edges.at(k) -> name) != m.end()){

                m[adjlist.at(i) -> edges.at(k) -> name] = adjlist.at(i) -> edges.at(k) -> indegree;
            }

            if(adjlist.at(i) -> edges.at(k) -> indegree == 0){
                auto iterate = find(result.begin(),result.end(),adjlist.at(i) -> edges.at(k) -> name);
                if(iterate == result.end()){
                    result.push_back(adjlist.at(i) -> edges.at(k) -> name);
                }
            }
        }

    }
}
vector<int> jo; 
vector<int> jo2;
for(int i = 0; i < adjlist.size(); i++){
    jo.push_back(adjlist.at(i) -> indegree);
    for(int j = 0; j < adjlist.at(i)->edges.size(); j++){
        jo2.push_back(adjlist.at(i)->edges.at(j)->indegree);
    }
}
vector<int>::iterator x1 = find(jo.begin(),jo.end(),1);
vector<int>::iterator x2 = find(jo2.begin(),jo2.end(),1); 
if( x1 == jo.end() && x2 == jo2.end()){
    isDone = false;
}


}

for(int i = 0; i < result.size(); i++){
    s = s + result.at(i) + " " ;
}
cout << s << endl;

    // while(q.empty() == false){
    //     Vertex* x = q.front();
    //     q.pop();
    //     s += x -> name;
    // }
    // cout << s << endl;

}

void helper(map<string, int> m, Vertex* v){
    map<string, int>::iterator it; 
    for(it = m.begin(); it != m.end(); it++ ){
        if(v -> name == it -> first){
            v -> indegree = it -> second;
        }
    }
}


