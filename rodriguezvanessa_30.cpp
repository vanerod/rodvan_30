#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

int main(){
  
  int m = 100;
  double e = 1;
  double dx = 0.01;
  double dt = 0.01;
  double t_max= 2.0;
  double B= e* (dt/dx);
  int n = t_max/dt;
    
  double u [m];
  double uf[m];

  ofstream outfile;
  int i;
  int j ;


  for(i=0;i<m;i++){
    u[i] = sin(4* M_PI * i/m)/20;
  }

  outfile.open("data_v.dat");

    for(i=0;i<n;i++){
        for(j=1;j<m-1;j++){
            uf[j] = u[j] - (B/4*(pow(u[j+1],2)-pow(u[j-1],2)))+ (B*B/8)*((u[j+1] + u[j])*( (pow(u[j+1],2)) -  (pow(u[j],2))) - ((u[j] + u[j-1])) * ((pow(u[j],2))-(pow(u[j-1],2))));
        }
  
     
        for(j=1;j<m;j++){
            outfile << u[j] << " ";
        }
   
        outfile << "\n";
    
        for(j=1;j<m;j++){
            u[j] = uf[j];
        }

    }
    outfile.close();
    return 0;
}
