#include<iostream>
#include<vector>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;
using std::clock_t;

const int SIZE = 150000;

void build_vector( const int& size, vector<int> * v ){

  for( int i = 0; i < size; i++ ){
    v->push_back( rand() % size );
  }
}

void cout_vector( vector<int> * v ){
  
  for( int& k : *v ){
    cout << k << endl;
  }
}

void insertion_sort( vector<int> * v ){

  int rightSide = -1;
  int j = -1;

  for( int i = 1; i < v->size(); i++ ){
    rightSide = v->at( i );
    j = i - 1;

    while( j >= 0 && v->at( j ) > rightSide ){
      v->at( j + 1 ) = v->at( j );
      j--;
    }
    v->at( j + 1 ) = rightSide; 
  }
}

int main(){

  clock_t start;
  double elapsed_time;

  vector<int> *data = new vector<int>();
  
  build_vector( SIZE, data ); 

  start = clock();
  insertion_sort( data );
  elapsed_time = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << "Elapsed_Time for insertion_sort( " << SIZE << " ) :" << elapsed_time;
  return 0;
}


