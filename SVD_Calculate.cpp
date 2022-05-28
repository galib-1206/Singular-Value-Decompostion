#include "header.h"

double SVD_func(){


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

    transpose_func(a, a_T ,2,2);

    Multiply(a,a_T,b,2,2,2);

    det=b[0][0]*b[1][1]-b[0][1]*b[1][0];

    trace=-b[0][0]-b[1][1];

    ev1=((-trace+sqrt((trace*trace)-(4*det)))/2);

    ev2=((-trace-sqrt((trace*trace)-(4*det)))/2);

    cout<<"\n eigen value1:"<<ev1;
    cout<<"\n eigen value2:"<<ev2;
    cout<<"\n"<<endl;

    double  x=(b[0][0]-ev1);
    double y=(-b[0][1]);
    double z=(b[0][0]-ev2);

    cout<<"\n eigen vector1: \n \t ["<<y<<"\n"<<"\t"<<x<<"]";
    cout<<"\n eigen vector2:\n \t ["<<y<<"\n"<<"\t"<<z<<"]" << endl;
    cout<<"\n"<<endl;

//singular value
    double s1=sqrt(fabs(ev1));
    double s2=sqrt(fabs(ev2));

    double eigenValMat [N][N] = {{ev1,0},
        {ev2,0}
    };
//printing sigma matrix

   cout<<"Sigma matrix:\n ";
    for(int i=0; i<2; i++)
    {

        for(int j=0; j<2; j++)
        {
            cout<<eigenValMat[i][j] << "   ";
        }
        cout << endl;
    }
    cout<<"\n"<<endl;



    double eigenVectorMat[N][N] = {{y, x}, {y, z}};

    cout<<"Eigen Vector Matrix:\n " ;
    for(int i=0; i<2; i++)
    {

        for(int j=0; j<2; j++)
        {
            cout<<eigenVectorMat[i][j] << "   ";
        }
        cout << endl;
    }

    double eigenVactorMat1[N][N]= {y,x};
    double eigenVectorMat2[N][N]= {y,z};
    double res1[N][N];
    double res2[N][N];

    Multiply( b,eigenVactorMat1, res1, 2, 2, 1);
    Multiply( b, eigenVectorMat2, res2, 2, 2, 1);

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
            U[i][j+1]=u1[i][j];
        }

    }

    //SVD calculating
    //SVD=U * eigenValueMat* Transpose(V)

    double U_eigenValueMat[N][N];
    double eigenVectorTransMat [N][N];
    double SVD [N][N];

    transpose_func(eigenVectorMat, eigenVectorTransMat,2,2);
    Multiply( U, eigenValMat,  U_eigenValueMat, 2, 2, 2);
    Multiply( U_eigenValueMat,  eigenVectorTransMat, SVD, 2, 2,2);

//print SVD
cout<<"SVD:\n ";
    for(int i=0; i<2; i++)
    {

        for(int j=0; j<2; j++)
        {
            cout<<SVD[i][j]<<"   ";
        }
        cout << endl;

    }
}





