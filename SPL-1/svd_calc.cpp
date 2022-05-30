#include "header.h"

double SVD_func()
{


    double det,trace,ev1,ev2;
    double a[N][N]= {0};
    printf("enter elements of 2*2 matrix :");

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            switch(i)
            {
            case 0:
                cout<<"\n a"<<(j+1)<<":";
                break;
            case 1:
                cout<<"\n b"<<(j+1)<<":";
                break;
            }
            cin>>a[i][j];
        }
    }

    double a_T[N][N],b[N][N];
    //print_matrix(a,2,2);

    transpose_func(a, a_T,2,2);
   // print_matrix(a_T,2,2);

    Multiply(a,a_T,b,2,2,2);
   // print_matrix(b,2,2);

    det=b[0][0]*b[1][1]-b[0][1]*b[1][0];

    trace=-b[0][0]-b[1][1];

    ev1=((-trace+sqrt((trace*trace)-(4*det)))/2);

    ev2=((-trace-sqrt((trace*trace)-(4*det)))/2);

    cout<<"\n eigen value1:"<<ev1;
    cout<<"\n eigen value2:"<<ev2;
    cout<<"\n"<<endl;

   // cout<<b[0][0] << " --" <<b[0][1] << endl;

    /* b[0][0]-=ev1;
     b[1][1]-=ev1;

      b[0][0]/=b[0][0];
       b[0][1]/=b[0][0];
       */



    double  x1=(b[0][0]-ev1)/(b[0][0]-ev1);
    double y1=-1*(b[0][1])/(b[0][0] -ev1);


    double  x2=(b[0][0]-ev2)/(b[0][0]-ev2);
    double y2=-1*(b[0][1])/(b[0][0] -ev2);

    //cout << "---(" << (-y) << "," << x << ")";

    // b[0][0]/=b[0][0]; //after reducing the row, we have only the first row..
    // y=(b[0][1])/b[0][0];
    //double z=(b[0][0]-ev2);

    cout<<"\neigen vector1:\n \t ["<<y1<<"\n"<<"\t"<<x1<<"]";
    cout<<"\neigen vector2:\n \t ["<<y2<<"\n"<<"\t"<<x2<<"]" << endl;
    cout<<"\n"<<endl;

//singular value
    double s1=sqrt(fabs(ev1));
    double s2=sqrt(fabs(ev2));

    double singularValMat [N][N] = {{s1,0},{0,s2}};
//printing sigma matrix

    cout<<"Sigma matrix:\n ";
    for(int i=0; i<2; i++)
    {

        for(int j=0; j<2; j++)
        {
            cout<<singularValMat[i][j]<<"....";
        }
        cout << endl;
    }
    cout<<"\n"<<endl;


    double eigenVectorMat[N][N] = {{y1, y2}, {x1, x2}};

    cout<<"Eigen Vector Matrix:\n " ;
    for(int i=0; i<2; i++)
    {

        for(int j=0; j<2; j++)
        {
            cout<<eigenVectorMat[i][j] << "\t\t";
        }
        cout << endl;
    }

    double eigenVactorMat1[N][N]= {y1,x1};
    double eigenVectorMat2[N][N]= {y2,x2};
    double res1[N][N];
    double res2[N][N];

    Multiply( a,eigenVactorMat1, res1, 2, 2, 1);
    Multiply( a, eigenVectorMat2, res2, 2, 2, 1);

    double u1[N][N]= {};

    for(int i=0; i<2; i++)
    {

        for(int j=0; j<1; j++)
        {
            u1[i][j]=res1[i][j]/s1;
        }

    }


    double u2[N][N]= {};

    for(int i=0; i<2; i++)
    {

        for(int j=0; j<1; j++)
        {
            u2[i][j]=res2[i][j]/s2;
        }

    }

    // U = [u1 u2]

    double U[N][N]= {};

    for(int i=0; i<2; i++)
    {

        for(int j=0; j<1; j++)
        {
            U[i][j]=u1[i][j];
        }

        for(int j=0; j<1; j++)
        {
            U[i][j+1]=u2[i][j];
        }

    }

    //SVD calculating
    //SVD=U * eigenValueMat* Transpose(V)

    double U_singularValueMat[N][N];
    double eigenVectorTransMat [N][N];
    double SVD [N][N];

    transpose_func(eigenVectorMat, eigenVectorTransMat,2,2);
    Multiply( U, singularValMat,  U_singularValueMat, 2, 2, 2);
    Multiply( U_singularValueMat,  eigenVectorTransMat, SVD, 2, 2,2);

//print SVD
    cout<<"\n\nSVD:\n ";
    for(int i=0; i<2; i++)
    {

        for(int j=0; j<2; j++)
        {
            cout<<SVD[i][j]<<"\t\t";
        }
        cout << endl;

    }
}





