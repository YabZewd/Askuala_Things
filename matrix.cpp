#include <iostream>
#include <iomanip>

using namespace std;


void calculateMatrix(int, int , int , int ); // Prototype of the function.

int main()
{
     int n=0, m=0;
     int columnMatri, rowMatri, columnMatri2, rowMatri2;
    while(n<100){cout<<"-";
    n++;}
    cout<<endl<<endl;
    cout<<setw(60) <<"PlEASE ENTER THE ORDER OF THE MATRIX."<<endl<<endl; // Accepts the order from the user.

    while(m<100){cout<<"-";
    m++;}
    cout<<endl<<endl;
    
    cout<< "Number of rows of the first matrix: ";
    cin>>rowMatri;
    cout<<"Number of columns of the first matrix: ";
    cin>>columnMatri;
    cout<< "Number of rows of the second matrix: ";
    cin>>rowMatri2;
    cout<<"Number of columns of the second matrix: ";
    cin>>columnMatri2;
    cout<<endl;
    
calculateMatrix(rowMatri,columnMatri,rowMatri2,columnMatri2);  //Calls for the function calculateMatrix.
    
    
    return 0;
}

void calculateMatrix(int ro1, int col1, int ro2, int col2){
    
     
    int matriArr[ro1][col1], matriArr2[ro2][col2];                  //Accept the variables.
    int sum[ro1][col1], difference[ro1][col1], product[ro1][col2]={0};
    
    cout<<"Input your first matrix 'A': "<<endl<<endl;    //Ask the user for the first matrix.
    for(int z=0; z<ro1; z++){
        for (int y=0; y<col1; y++){
            cout<<"Enter row "<<z+1<<" "<<"column "<<y+1<<"\t";
            cin>> matriArr[z][y];
        }
    }
            cout<<endl<<endl;

    cout<<"Input your second matrix 'B'"<<endl<<endl;   //Ask the user for the second matrix.

            for(int w=0; w<ro2; w++){
                for (int a=0; a<col2; a++){
                     cout<<"Enter row "<<w+1<<" "<<"column "<<a+1<<"\t";
                        cin>> matriArr2[w][a];
        }
        }
             cout<<endl<<endl;

    
    char oprnd;
    cout<<"What operation do you want to perform? \n";      //Ask for the operation to be performed.
    cout<<"Enter '+' for addition, '-' for subtraction and '*' for multiplication. ";
    cin>>oprnd;
    
   switch (oprnd){
    case '+' :
                if (ro1==ro2 && col1==col2){
                    for(int i=0; i<ro1; i++){
                        for (int j=0;j<col1; j++){
                    sum[i][j]= matriArr[i][j] + matriArr2[i][j];    //Addition of the matrices and store in sum.
                        }
                      cout<<endl; 
                    }
                
                 cout<<"The sum of matrix A and B is:"<<endl<<endl;
                     for(int q=0; q<ro1; q++){
                           for (int se=0;se<col1; se++){
                                cout<<sum[q][se]<<" ";        //Display the sum of the matrices.
                        }
                            cout<<endl; 
                          }
                    
                }
                       
            else { cout<< "Addition can not be performed. ";} // If the number of rows and columns don't match.

    break;
    case '-' : 
                if (ro1==ro2 && col1==col2){
                    for(int mek=0; mek<ro1; mek++){
                        for (int enes=0;enes<col1; enes++){
                   
                    difference[mek][enes]= matriArr[mek][enes] - matriArr2[mek][enes]; // Differnece
                        }
                      cout<<endl; 
                    }
                 cout<<"The difference between matrix A and B is:"<<endl<<endl;
                 for(int di=0; di<ro1; di++){
                           for (int lp=0;lp<col1; lp++){
                                cout<<difference[di][lp]<<" ";  // Display the difference of the matrices.
                        }
                            cout<<endl; 
                          }
                    
                }
        else { cout<< "Subtraction can not be performed. ";}  // If the number of rows and columns don't match.

    break;
    case '*':
                if (col1==ro2){
                    for(int mab=0; mab<ro1; mab++){
                        for (int azat=0;azat<col2; azat++){
                            for(int i=0;i<col1;i++){
             
             product[mab][azat]= product[mab][azat] + (matriArr[mab][i] * matriArr2[i][azat]); // Product of A & B
                        }
                            
                        }
                    }
                 cout<<"The product of matrix A and B is:"<<endl<<endl;
                 for(int pr=0; pr<ro1; pr++){
                           for (int mu=0;mu<col1; mu++){
                                cout<<product[pr][mu]<<" "; //Display the product.
                        }
                            cout<<endl; 
                          }
                    
                }
            else { cout<< "Multiplication can not be performed. ";}// If column 1 is not equal to row 2 
    break;
    
    default:
    cout<<endl<<"You didnt enter the correct operand. "; // If the user inputs different operand.

    }
}