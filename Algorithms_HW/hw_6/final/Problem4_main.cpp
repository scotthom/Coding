// name1: Scott Hom
// name2: Paul Ngouchet


#include <string>
#include <fstream>
#include "Pangram.h"
#include <algorithm>
#include "Trie.h"
#include <sstream>

 vector<Pangram*> vec_pangram;



 struct compare {
    bool operator()( Pangram* first,  Pangram* second) {
        return first->size() < second->size();
    }
};



void fourC()
{
   string word; 
ifstream myfile;
myfile.open("dictionary.txt");

    Trie* trie = new Trie();

while (!myfile.eof())
{
 
	myfile >> word ;
	if((word.find('p') != std::string::npos) || (word.find('P') != std::string::npos))
		continue;
	else
	{
		trie->addWord(word);
	}


}

myfile.close();


   string data; 
myfile.open("BigData.txt");
int count = 0 ;

 

while (!myfile.eof())
{
 
	myfile >> data ;
	if(trie->searchWord(data) == true)
		count++;


}
myfile.close();

cout<< count << endl ;

}


void fourB()
{

	string str;
	string line;
  ifstream myfile ("BigData.txt");
     getline (myfile,line) ;
       
    myfile.close();

    str = line ;
	int count = 0 ;
	  vector<bool> used(26, false);
 
    int index;
int length = str.length() ;
    int actualstart = 0;
     int actualend = 0 ;
int a = 0 ;
int b = 0  ;


    while( true )
    {
 
    for (int i=actualstart; i<length; i++)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            index = str[i] - 'A';
 
        
        else if('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
 
        
        used[index] = true;



         for (int j=0; j<=25; j++)
	         {
	        if (used[j] == false)
	        {	
	        	count = 0 ;
	          	break;
	          }

	          count++;

	            }
	           
	      if( count == 26)
		      {
		      	
		      	count = 0 ;
		      	actualend = i;
		      	
		      	Pangram* pangram = new Pangram(actualstart , actualend);
		      	vec_pangram.push_back(pangram);
		     
		     for(int z = 0 ; z < used.size() ; z++)
		     	used[z] = false ;


		      	break;
		      
	    }

	    b = i ;
	   
	}
		

    for (int i= (actualend+1) ; ; i--)
    {
    	
        if ('A' <= str[i] && str[i] <= 'Z')
            index = str[i] - 'A';
 
        
        else if('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';
 
        
        used[index] = true;

      

         for (int j=0; j<=25; j++)
	         {
		        if (used[j] == false)
		        {	
		        	count = 0 ; 
		          	break;
		          }

		          count++;

		            }
		  
	      if( count == 26)
			      {
			      	count = 0 ;
			      
			      	actualstart = i + 1;
			  	
			      	Pangram* pangram = new Pangram(i, actualend);
			      vec_pangram.push_back(pangram);
			        
		     for(int z = 0 ; z < used.size() ; z++)
		     	used[z] = false ;

			      	break;
			      
		    }


}
a = b;


			if(vec_pangram.size() > 3)
			{
			if( ((vec_pangram[vec_pangram.size() - 1]->first) == (vec_pangram[vec_pangram.size() - 3]->first) )&& ((vec_pangram[vec_pangram.size() - 1]->end) == (vec_pangram[vec_pangram.size() - 3]->end) )  )
				break;
	}

if( actualend == (length - 1) )
	break;



}

compare c;
sort(vec_pangram.begin(), vec_pangram.end(), c);

 cout<< "size of pangram is " << vec_pangram[0]->size() << endl;

for(int i = vec_pangram[0]->first ; i <= vec_pangram[0]->end ; i++)
	cout<< str[i] ;

cout<< endl ;


 }

void fourA()
{
    string line;
    fstream file;
    file.open("BigData.txt");

    bool num_pres = false;
    int word_count = 0;

    while (getline(file,line)){
        int len_line = line.length(); 

        for(int i = 0; i < len_line; i++){
            if(line[i] > 47 && line[i] < 58)
                num_pres = true;

            if(line[i] == ' ' && num_pres == false){
                ++word_count;
            }
                
            else if (line[i] == ' ' && num_pres == true )
                num_pres = false;

            if(i == len_line - 1 && num_pres == false){
                ++word_count;
            }
                

        }
    }

    cout << "The number of words that only contain alphabetical charactures is " << word_count << "." << endl;

}
 


int main()
{

    fourA();
    fourB();
    fourC();
    
}


























