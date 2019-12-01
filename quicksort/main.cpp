#include<iostream>
#include<vector>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;
using std::clock_t;

const int SIZE = 300000;

void build_vector( const int& size, vector<int>& v ){

  for( int i = 0; i < size; i++ ){
    v.push_back( rand() % size );
  }
}

void cout_vector( vector<int>& v ){
  for( int& k : v ){
    cout << k << " ,";
  }
}


int partition( vector<int>& v,  int low, int high ){
  int pivot_index = ( low + high ) / 2;
  int pivot_value = v[pivot_index];

  int i = low;
  int k = high;
  int temp;

  while( i <= k ){
    while( v[i] < pivot_value ){ i++; }
    while( v[k] > pivot_value ){ k--; }

    if( i <= k ){
      temp = v[i];
      v[i] = v[k];
      v[k] = temp;
      i++;
      k--;
    }
  }

  return i;
}

void quick_sort( vector<int>& v, int low, int high ){
  
  if( low < high ){
    int index = partition( v,  low, high );
    quick_sort( v, low, index - 1 );
    quick_sort( v, index , high );
  }
}

int main(){

  clock_t start;
  double elapsed_time;

  vector<int> data;
  
  build_vector( SIZE, data ); 

  start = clock();
  quick_sort( data, 0 , data.size() - 1 );
  elapsed_time = ( clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << endl << "Elapsed_Time for quick_sort( " << SIZE << " ) :" << elapsed_time;
  return 0;
}


