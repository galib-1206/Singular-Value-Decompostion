#include"header.h"

int n;
double *a,*b,*c, r, s, old_r, old_s,dr,ds,root_p, root_q;
bool last = false;
//for the rest equation

void new_arr()
{
    a = new double[N];
    b = new double[N];
    c = new double[N];
}

void del_arr()
{
    delete a;
    delete b;
    delete c;

}


double absolute(double x)
{
    //return abs value
    if(x<0)
    {
        x *= -1;
    }

    return x;
}



double remove_eror(double val)
{
    //floating point eror
    int integer = val;
    if(absolute(integer - val) <= phi)
    {

        val = (double)integer;
    }

    return val;
}

void printRoot(double x,double p, double q)
{

    if(!last)
    {
        //for r and s , we need to change sign of r and s
        p = (-1)*remove_eror(p);
        q =(-1)*remove_eror(q);
    }
    else
    {
        // we find solution from rest of equation
        p = remove_eror(p);
        q = remove_eror(q);
    }

    double determine = (p*p) - (4*x*q);


    if(determine<0)
    {
        determine *= -1;

        determine = sqrt(determine);

        if(p == 0)
        {
            //pure imaginary number
            if((determine/(2*x)) == 1)
            {
                //coefficient 1
                cout<<"\tRoot: "<<"i"<<endl;
                cout<<"\tRoot: "<<"-i"<<endl;
            }
            else
            {

                cout<<"\tRoot: "<<(determine/(2*x))<<"i"<<endl;
                cout<<"\tRoot: "<<(determine/(2*x))<<"-i"<<endl;
            }
        }
        else
        {
            // not a pure imaginary number
            if((determine/(2*x)) == 1)
            {
                //coefficient 1 , not necessary to print
                cout<<"\tRoot: "<<((-p)/(2*x))<<" + "<<"i"<<endl;
                cout<<"\tRoot: "<<((-p)/(2*x))<<" - "<<"i"<<endl;
            }
            else
            {
                //there are coefficient
                cout<<"\tRoot: "<<((-p)/(2*x))<<" + "<<(determine/(2*x))<<"i"<<endl;
                cout<<"\tRoot: "<<((-p)/(2*x))<<" - "<<(determine/(2*x))<<"i"<<endl;
            }
        }
    }
    else
    {
        //cout<<determine<<endl;
        determine = sqrt(determine);
        //cout<<determine<<endl;
        double first = remove_eror(((-p) - determine)/(2*x));
        double second =  remove_eror(((-p) + determine)/(2*x));

        cout<<"\tRoot: "<<first<<endl;
        cout<<"\tRoot: "<<second<<endl;

    }
}



void print_rootOne(double x, double y)
{
    // If existance equation has only one solution
    //x *= -1;
    //y *= -1;

    double root = -(y/x);

    cout<<"\tRoot: "<<root<<endl;
}






void cal_r_s()
{
    //for iteration we need to find r and s

    dr = (b[0]*c[3] - b[1]*c[2]) / (c[2]*c[2] - c[1]*c[3]);
    ds = (b[1]*c[1] - b[0]*c[2]) / (c[2]*c[2] - c[1]*c[3]);

    old_r = r ;
    old_s = s;

    r += dr;
    s += ds;
}


void cal_col(double p[], double q[])
{
    //iterate column to find solution
    q[n] = p[n];
    q[n-1] = p[n-1] + q[n]*r;

    for(int i=n-2; i>=0; i--)
    {
        q[i] = p[i] + (q[i+1]*r) + (q[i+2]*s);
    }
}



void reduce_eqn()
{
    //After iteration, found two solution and the equations's power reduce by two.
    //Replace a[] by b[]
    for(int i=0; i<n-1; i++)
    {
        a[i] = b[i+2];
    }

    n -= 2;
}


void RootFinding()
{
    //iteration until equation goes to power 1 or 2
    double ratio_s, ratio_r;

    if(n == 0)
    {
        cout<<"No such variable.\n Wrong input\n\n";
        exit(0);
    }
    else if(n == 1)
    {
        print_rootOne(a[n], a[n-1]);
    }
    else if(n == 2)
    {
        last = true;
        printRoot(a[n], a[n-1], a[n-2]);
    }
    else
    {

        while(1)
        {
            cal_col(a,b);
            cal_col(b,c);

            cal_r_s();

            ratio_s = ds/old_s;
            ratio_r = dr/old_r;


            if(((absolute(b[0]) <= phi) && (absolute(b[1]) <= phi)) || ((absolute(ratio_r) <= phi) || (absolute(ratio_s) <= phi)))
            {

                printRoot(1,r,s);

                if(n == 4)
                {
                    last = true;
                    printRoot(b[n],b[n-1],b[n-2]);
                    break;
                }

                if(n == 3)
                {
                    print_rootOne(b[n], b[n-1]);
                    break;
                }

                reduce_eqn();
            }
        }
    }
}


void Get_Coefficient(double pass[], int total)
{
    new_arr();
    for(int i= total; i>=0; i--)
    {
        a[i] = pass[i];
    }
    n = total;


    r = a[n-1]/a[n];
    s = a[n-2]/a[n];

    if(r == 0)
    {
        r = 0.1;
    }

    if(s ==0)
    {
        s = 0.1;
    }

    RootFinding();

    del_arr();         //deallocate memory
    return;
}



