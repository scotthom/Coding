// ------------------------ Adjacency List ------------------------

// Sumarry: The adjacency list is stored in an array of int vectors called adj_list. The array is of length number of vertex (V) plus one. It's plus 1 
// becuase the number V is stored in adj_list[0][0]. The adjacency information for each vertex in the adjacency list is stored in the array ellements 
// 1 - V, which each contain a vector that contains the information for that vertex.



#include <iostream>
#include <queue>
#include "BFSearch.h"
#include <fstream>
#include <vector>

using namespace std;

vector<int> * make_adj_list();
void print_arr(vector<int> *arr, int len_arr);

int main() {

    string file = "maze.txt";                       //file 

    vector<int> *adj_list_p = make_adj_list();  //make adjacency list (pointer to array of int vectors.)

    int num_v = adj_list_p[0][0];
					                   //number of vertex
    if(adj_list_p[1].empty() == true || adj_list_p[num_v].empty() == true)
    {
    	cout << 0 << endl ;
    	return 0 ;
    }
                                              //print adjacency list
Graph g(num_v + 1);
int k = 1;



    for(int i = 1 ; i < adj_list_p[0][0] ; i++)
    {
        for( int j = 0 ; j < adj_list_p[i].size() ; j++)
            {
               
                if(adj_list_p[i][j] == 0 || adj_list_p[i].empty() == true)
                {
                    k++;
                    break;
                }
                else
                {
                  
                    g.addEdge(k, adj_list_p[i][j]);
                }
        }
        k++;
    }
 

 

    g.BFS(1);

        return 0 ;
    }
void print_arr(vector<int> *arr, int len_arr)
{
	int vertexs;

	for(int i = 1; i < len_arr+1; i++){
		vertexs = (arr + i)->size();				//number of adjacencies for each vector

		if(arr[i].size() != 0){
			if(vertexs == 0)
				cout << i << ": 0" << endl;

			else{
				bool one_ellem = true;

				for(int j = 0; j < vertexs; j++){
					if(j == 0 && vertexs == 1){
						cout << i << ": " << arr[i][j] << " " << endl;
					}
					else if(j == 0){
						cout << i << ": " << arr[i][j] << " ";
					}
					else if(j > 0 && j < vertexs-1){
						cout << arr[i][j] << " ";
					}
					else{
						cout << arr[i][j] << endl;;
					}

				} 

			} 
		}

	}

}

vector<int> * make_adj_list()
{

	string line;
	ifstream file;
	file.open("maze.txt");

	getline(file,line);						// read the first line of txt file to get it's length
	int n = line.length(); 
	int maze[n*n];							// initialize a 1D array called maze to simulate 2D array

	int temp;

	for(int i = 0; i < n; i++){				// add numbers to maze
		temp = (int(line[i]) - 48);			// convert ascii number read in to int number
		maze[i] = temp;
	}

	int i = 1;								// add numbers from 2nd - last line

	while(getline(file,line)){
		for (int j = 0; j < n; ++j) 
		{
			temp = (int(line[j]) - 48);
			maze[i*n+j] = temp;				//simulate adding each line to 2D array
		}
		++i;								//increment to go to next line 
	}

	int len_arr = (sizeof(maze)/sizeof(*maze));

	vector<int> * adj_list = new vector<int> [len_arr+1]; 		// set adjacency list

	int row = 0;												// row is to keep track of the text file's rows from 0 - (V-1)
	int line_trav = 0;											// ellement in row
	int neighbors = 0;											// number of neighbors each vertex has 

	adj_list[0].push_back(len_arr);								// store number vertexs

	for(int i = 1; i < len_arr+1; i++){

			int ellem = i-1; 						// shift i back 1 to access the ellements stored in the array starting from 0
			++line_trav;							// keep track of ellement traversing in line

			if(row == 0){								// top row

				if(maze[ellem] == 1){

					if(i == 1){								// compensate for top left corner
						if(maze[ellem+n] == 1){
							adj_list[i].push_back(i+n);
							++neighbors;					// keep track numer of neigbors
						}

						if(maze[ellem+1] == 1){
							adj_list[i].push_back(i+1);
							++neighbors;
						}
						if(neighbors == 0){
							adj_list[i].push_back(0);		// IF neigbors is 0. append 0 to mean no adjacent verteices	
						}

						neighbors = 0;

					}

					else if(i > 1 && i < n) {				//columns in row
						if(maze[ellem+n] == 1){
							adj_list[i].push_back(i+n);
							++neighbors;

						}
						if(maze[ellem-1] == 1){
							adj_list[i].push_back(i-1);
							++neighbors;

						}
						if(maze[ellem+1] == 1){
							adj_list[i].push_back(i+1);
							++neighbors;

						}

						if(neighbors == 0){
							adj_list[i].push_back(0);
						}

						neighbors = 0;

					}

					else if(i == (row*n + (n))){				// compensate for top right corner
						if(maze[ellem+n] == 1){
							adj_list[i].push_back(i+n);
							++neighbors;

						}
						if(maze[ellem-1] == 1){
							adj_list[i].push_back(i-1);
							++neighbors;

						}

						if(neighbors == 0){
							adj_list[i].push_back(0);
						}

						neighbors = 0;

					}

				}

			}

			else if (row > 0 && row < n-1){					// middle rows

				if(maze[ellem] == 1){

					if(i == row*n+1){
						if(maze[ellem-n] == 1){
							adj_list[i].push_back(i-n);

						}
						if(maze[ellem+n] == 1){
							adj_list[i].push_back(i+n);

						}
						if(maze[ellem+1] == 1){
							adj_list[i].push_back(i+1);

						}

					}

					else if(i > row*n+1 &&  i < row*n + n) {	
						if(maze[ellem-n] == 1){
							adj_list[i].push_back(i-n);

						}
						if(maze[ellem+n] == 1){
							adj_list[i].push_back(i+n);

						}
						if(maze[ellem-1] == 1){
							adj_list[i].push_back(i-1);

						}
						if(maze[ellem+1] == 1){
							adj_list[i].push_back(i+1);

						}

					}


					else if(i == (row*n + (n))){
						if(maze[ellem-n] == 1){
							adj_list[i].push_back(i-n);

						}
						if(maze[ellem+n] == 1){
							adj_list[i].push_back(i+n);

						}
						if(maze[ellem-1] == 1){
							adj_list[i].push_back(i-1);

						}

					}

				}
				
			}

			else{											// bottom row
				
				if(maze[ellem] == 1){

					if(i == row*n+1){

						if(maze[ellem-n] == 1){
							adj_list[i].push_back(i-n);

						}
						if(maze[ellem+1] == 1){
							adj_list[i].push_back(i+1);

						}

					}

					else if(i > row*n+1 &&  i < row*n + n) {
						if(maze[ellem-n] == 1){
							adj_list[i].push_back(i-n);
							++neighbors; 
						}
						if(maze[ellem-1] == 1){
							adj_list[i].push_back(i-1);
							++neighbors; 
						}
						if(maze[ellem+1] == 1){
							adj_list[i].push_back(i+1);
							++neighbors; 
						}
						if(neighbors == 0){
							adj_list[i].push_back(0);
						}

						neighbors = 0;

					}


					else if(i == (row*n + (n))){
						if(maze[ellem-n] == 1){
							adj_list[i].push_back(i-n);

						}
						if(maze[ellem-1] == 1){
							adj_list[i].push_back(i-1);

						}

					}

				}
				
			}

			if(line_trav == n){								// keep track of rows
					++row;
					line_trav = 0;
			}

	} 

	return adj_list;

}