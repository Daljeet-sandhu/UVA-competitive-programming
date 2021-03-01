//Daljeet Singh
//105165075

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>                        //declaring libraries
#include <queue>

using namespace std;                     //global varibale
typedef struct {
    string parent;                     //declaring structure
    vector<string> childs;
    int depth;
} node;

int min(int a, int b) {                             //function
    return  a < b ? a : b;
}
int main() {                                                                   //main function
    char child[31], parent[31];
    unordered_map<string, node> tree;
    unordered_set<string> roots;                       //declaring variables
    queue<node> bfs;
    while( scanf("%31s %31s", child, parent) != EOF && (string)child != "no.child" && (string)parent != "no.parent"){ 
        auto child_node = tree.find(child);                                          //while loop
        auto parent_node = tree.find(parent);
        if (child_node == tree.end()){
            tree[child] = {parent , {}};                                                             //if condition
        }
        else {                                                                              //else condition
            roots.erase(child);
            tree[child].parent = parent;
        }
        if (parent_node == tree.end()){
            tree[parent] = {"", {child}};                                                             //if condition
            roots.insert(parent);
        }
        else {                                                                              //else condition
            tree[parent].childs.push_back(child);
        }
    }
    for(auto root : roots){ 
        tree[root].depth = 0;                                //for loop
        bfs.push(tree[root]);
    }
    while (!bfs.empty()){                                          //while loop
        node curr_node = bfs.front();
        bfs.pop();
        for(string child : curr_node.childs){
            tree[child].depth = curr_node.depth + 1;
            bfs.push(tree[child]);
        }
    }
    while( scanf("%31s %31s", child, parent) != EOF){                                          //while loop
        auto lnode = tree.find(child), rnode = tree.find(parent), lnode_tmp = lnode, rnode_tmp = rnode;
        if (lnode == tree.end() || rnode == tree.end()){
            printf("no relation\n");
        }
        else {

            if (lnode->second.depth != rnode->second.depth){                                                             //if condition
                while(rnode_tmp != tree.end() && rnode_tmp->second.depth > lnode->second.depth){
                    rnode_tmp = tree.find(rnode_tmp->second.parent);                                          //while loop
                }
                while(lnode_tmp != tree.end() && lnode_tmp->second.depth > rnode->second.depth){
                    lnode_tmp = tree.find(lnode_tmp->second.parent);
                }
            }
            if( lnode->second.parent == rnode->second.parent){
                printf("sibling\n");
            }
            else if(lnode->first == rnode_tmp->first) {                                                                              //else condition
                int delta = rnode->second.depth - lnode->second.depth;
                for(int i=1; i < delta ; i++){
                    if(i == delta - 1)
                        printf("grand ");
                    else 
                        printf("great ");
                }
                printf("parent\n");
            }
            else if(rnode->first == lnode_tmp->first) {
                int delta = lnode->second.depth - rnode->second.depth;
                for(int i=1; i < delta ; i++) {
                    if(i == delta - 1)                                                             //if condition
                        printf("grand ");
                    else 
                        printf("great ");
                }
                printf("child\n");
            }
            else {                                                                              //else condition
                while(rnode_tmp != tree.end() && lnode_tmp != tree.end() && rnode_tmp->first != lnode_tmp->first){
                    rnode_tmp = tree.find(rnode_tmp->second.parent);                                          //while loop
                    lnode_tmp = tree.find(lnode_tmp->second.parent);
                }
                if(rnode_tmp != tree.end() && lnode_tmp != tree.end()){                                                             //if condition
                    int n = rnode->second.depth - rnode_tmp->second.depth - 1,
                        m = lnode->second.depth - lnode_tmp->second.depth - 1,
                        k = min(n, m),
                        j = abs(n - m);
                    if (j==0)
                        printf("%d cousin\n", k);
                    else
                        printf("%d cousin removed %d\n", k , j);                                                                              //else condition
                            
                }
                else {
                    printf("no relation\n");                                                          //printing results

                }
            }
        }
    }
    return 0;
}