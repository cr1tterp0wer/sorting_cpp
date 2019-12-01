#include<iostream>
#include<vector>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;
using std::clock_t;

const int SIZE = 300000;

void build_vector( const int& size, vector<int> * v ){

  for( int i = 0; i < size; i++ ){
    v->push_back( rand() % size );
  }
}

void cout_vector( vector<int> * v ){
  for( int& k : *v ){
    cout << k << " ,";
  }
}

vector<int> merge( vector<int>& left_side, vector<int>& right_side ){

  vector<int> result;
  int left_i = 0, right_i = 0;

  while( left_i < left_side.size() && right_i < right_side.size() ){

    //if left is smaller than right, add to result
    if( left_side[left_i] < right_side[right_i] ){
      result.push_back( left_side[left_i] );
      left_i++;
    }else{
      result.push_back( right_side[right_i] );
      right_i++;
    }
  }

  //Push the left over data
  while( left_i < left_side.size() ){
    result.push_back( left_side[left_i] );
    left_i++;
  }

  while( right_i < right_side.size() ){
    result.push_back( right_side[right_i] );
    right_i++;
  }

  return result;
}

vector<int> merge_sort( vector<int>& v ){

  if( v.size() == 1 ){
    return v;
  }

  vector<int>::iterator midpoint = v.begin() + ( v.size() / 2 );

  vector<int> l( v.begin(), midpoint );
  vector<int> r( midpoint, v.end() );

  l = merge_sort( l );
  r = merge_sort( r );

  return merge( l, r );
}

int main(){

  clock_t start;
  double elapsed_time;

  vector<int> *data = new vector<int>();
  
  build_vector( SIZE, data ); 

  start = clock();
  vector<int> result = merge_sort( *data );
  elapsed_time = ( clock() - start ) / (double) CLOCKS_PER_SEC;
  
  cout << endl << "Elapsed_Time for merge_sort( " << SIZE << " ) :" << elapsed_time;
  return 0;
}


