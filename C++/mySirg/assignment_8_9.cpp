#include <iostream>
using namespace std;
class Date
{
    private :
            int d, m, y;
    public  :
            void setDate(int x, int y1, int z)
            {
                d = x;
                m = y1;
                y = z;
            }
            // char* getmonth(int m)
            // {
            //     switch(m)
            //     {
            //         case 1:
            //             return "jan";
            //         case 2:
            //             return "feb";
            //         case 3:
            //             return "mar";
            //         case 4:
            //             return "apr";
            //         case 5:
            //             return "may";
            //         case 6: 
            //             return "jun";
            //         case 7:
            //             return "jul";
            //         case 8:
            //             return "aug";
            //         case 9:
            //             return "sept";
            //         case 10:
            //             return "oct";
            //         case 11:
            //             return "nov";
            //         case 12:
            //             return "dec";
            //     }
            // }
            // void printDate()
            // {
            //     cout << "Date : " << d << "-" << getmonth(m) << "-" << y;
            // }
};
class Circle
{
    private :
            int rad;
    public :
            void getradius(int x)
            {
                rad = x;
            }
            float area()
            {
                return 3.14 * rad * rad;
            }
            float circumference()
            {
                return 2 * 3.14 * rad;
            }
};
class Complex
{
	int a;
	int b;
	public :
            Complex(){};
			Complex(int x, int y)
			{
				a = x;
				b = y;
			}
			void display()
            {
                cout << "complex number is " << a << "+" << b << "i" << endl;
            }
			Complex operator+(Complex c)
			{
				Complex temp;
				temp.a = a + c.a;
				temp.b = b + c.b;
				return temp;
			}
            Complex operator-(Complex c)
			{
				Complex temp;
				temp.a = a - c.a;
				temp.b = b - c.b;
				return temp;
			}
            Complex operator*(Complex c)
			{
				Complex temp;
				temp.a = a * c.a - b * c.b;
				temp.b = a * c.b + b * c.a;
				return temp;
			}
            bool operator==(Complex c)
			{
				if (a == c.a && b == c.b)
                {
                    return true;
                }
				else 
                    return false;
			}
};
class TestResult
{
    private:
        int roll_no, right, wrong;
        static int right_weightage, wrong_weightage;
    public:
        int net_score;
        void setroll(int roll){roll_no = roll;}
        void setright(int r){right = r;}
        void setwrong(int w){wrong = w;}
        int getroll(){return roll_no;}
        int getright(){return right;}
        int getwrong(){return wrong;}
        int netscore()
        {
            net_score = right * right_weightage + wrong * wrong_weightage;
            return net_score;
        }
};
void sortnetscore(TestResult a[], int size)
{
    TestResult t;
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        if(a[i].netscore() < a[j].netscore())
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
}
void display(TestResult a[], int size)
{
    cout << endl << "-------------------------------------------" << endl;   
    cout << "roll no   right   wrong   netscore" << endl;     
    for(int i = 0; i < size; i++)
    {
        cout << a[i].getroll() <<"    "<< a[i].getright() <<"     " << a[i].getwrong()<<"     "<< a[i].net_score <<endl;
    }
}
int TestResult:: right_weightage = 2;
int TestResult:: wrong_weightage = -1;
class Matrix
{
    private:
        int arr[3][3];    
    public:
        void setMatrix()
        {
            cout << "enter elements of matrix :" << endl;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << "enter element of [" << i << "]" << "[" << j << "]" << endl;
                    cin >> arr[i][j]; 
                }
            }
        }
        void showMatrix()
        {
            cout << "the matrix is :" << endl;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << arr[i][j] << "  ";
                }
                cout << endl;
            }
        }
        Matrix operator+(Matrix m)
        {
            Matrix t;
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    t.arr[i][j] = arr[i][j] + m.arr[i][j];
                }
            }
            return t;
        }
        Matrix operator-(Matrix m)
        {
            Matrix t;
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    t.arr[i][j] = arr[i][j] - m.arr[i][j];
                }
            }
            return t;
        }
        Matrix transpose()
        {
            Matrix t;
            for(int i=0; i<3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    t.arr[i][j] = arr[j][i];
                }
            }
            return t;
        }
        Matrix operator*(Matrix m)
        {
            Matrix t;
            int sum;
            for(int i=0; i<= 2; i++)
                for(int j=0; j<= 2; j++){
                    sum = 0;
                    for(int k=0; k<= 2; k++)
                        sum = sum + arr[i][k] * m.arr[k][j];
                        t.arr[i][j] = sum;  
                }
                return t;
            }
        bool is_singular()
        {
            if((arr[0][0] * ((arr[1][1]*arr[2][2]) - (arr[2][1]*arr[1][2])) -arr[0][1] * (arr[1][0]* arr[2][2] - arr[2][0] * arr[1][2]) + arr[0][2] * (arr[1][0] * arr[2][1] - arr[2][0] * arr[1][1])) == 0)
            return true;
        }
};
int main()
{
    // problem in date class for month name
    // Date d;
    // d.setDate(27,9,2003);
    // d.printDate();
    Matrix m,n,o;
    m.setMatrix();
    n.setMatrix();
    o = m * n;
    o.showMatrix();
    return 0;
}