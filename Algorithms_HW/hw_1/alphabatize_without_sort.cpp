//name: Scott Hom
//sources: obtain ascii characture value http://www.programiz.com/cpp-programming/examples/ASCII-value-character

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    string file1 = "words1.txt";
    string file2 = "words2.txt";
    string line1;
    string line2;
    vector<string> all_words;
    fstream myfile1;
    fstream myfile2;
    
    myfile1.open(file1);
    myfile2.open(file2);
    if (myfile1.is_open())
    {
        while ( getline (myfile1,line1) )
        {
            all_words.push_back(line1);
        }
        myfile1.close();
    }
    if (myfile2.is_open())
    {
        while ( getline (myfile2,line2) )
        {
            all_words.push_back(line2);
        }
        myfile2.close();
    }
    
//   Why doesnt this work with integer incremented for loop?
//    for(int i = 0; all_words.size(); i++){
//        cout << all_words[i] << endl; 
//    }
    
// why does the fact string type not equal mean the I cant derefrencec and use a function on something?
    
    for(vector<string>::iterator it = all_words.begin(); it != all_words.end(); it++){
        if(it->length() == (it+1)->length()){
            cout << *it << " = " << *(it+1) << endl;
            for(int i = 0; (it->length())-1; i++){
                
            }

        }
        if(it->length() > (it+1)->length()){
            cout << *it << " > " << *(it+1) << endl;
            for(int i = 0; (it->length())-1; i++){
                cout << (*it)[i] << endl;
            }
        }
            
        else if(it->length() < (it+1)->length()){
            cout << *it << " < " << *(it+1) << endl;
            for(vector<char>::iterator it_let = (it+1)->begin(); it_let != (it+1)->end(); it_let++){
               
            }
        }
        
    }
    
    return 0;
}